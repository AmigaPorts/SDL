#!/bin/bash
#
# release.sh -- Package and publish a GitHub release for libSDL2-amigaos3
#
# Usage:
#   scripts/release.sh              # Full release (tag + package + gh release)
#   scripts/release.sh --dry-run    # Show what would happen
#   scripts/release.sh --package-only  # Build artifacts without tagging/releasing
#
# Prerequisites:
#   - Docker (for cross-compilation)
#   - gh CLI (authenticated)
#   - Clean git working tree on main branch

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_DIR"

DRY_RUN=false
PACKAGE_ONLY=false

for arg in "$@"; do
    case "$arg" in
        --dry-run) DRY_RUN=true ;;
        --package-only) PACKAGE_ONLY=true ;;
    esac
done

# --- Read version ---
if [ ! -f VERSION ]; then
    echo "ERROR: VERSION file not found" >&2
    exit 1
fi
VERSION=$(cat VERSION | tr -d '[:space:]')
TAG="v${VERSION}"

echo "=== Release $TAG ==="

# --- Validate ---
if ! echo "$VERSION" | grep -qE '^[0-9]+\.[0-9]+\.[0-9]+$'; then
    echo "ERROR: VERSION '$VERSION' is not valid semver (X.Y.Z)" >&2
    exit 1
fi

if ! grep -q "\[${VERSION}\]" CHANGELOG.md 2>/dev/null; then
    echo "ERROR: CHANGELOG.md has no entry for [$VERSION]" >&2
    exit 1
fi

if [ "$PACKAGE_ONLY" = false ] && [ "$DRY_RUN" = false ]; then
    if [ -n "$(git diff --name-only HEAD)" ]; then
        echo "ERROR: Tracked files have uncommitted changes. Commit or stash first." >&2
        git diff --name-only HEAD >&2
        exit 1
    fi
    BRANCH=$(git branch --show-current)
    if [ "$BRANCH" != "main" ]; then
        echo "ERROR: Not on main branch (on $BRANCH)" >&2
        exit 1
    fi
    if git tag -l "$TAG" | grep -q "$TAG"; then
        echo "ERROR: Tag $TAG already exists" >&2
        exit 1
    fi
fi

# --- Build SDK ---
echo "Building libSDL2.a..."
if [ "$DRY_RUN" = true ]; then
    echo "[dry-run] Would run: make docker-build"
else
    make docker-build
fi

# --- Package SDK ---
SDK_NAME="libSDL2-amigaos3-sdk-${TAG}"
SDK_TARBALL="${SDK_NAME}.tar.gz"
STAGING="/tmp/${SDK_NAME}"

echo "Packaging SDK: $SDK_TARBALL"
rm -rf "$STAGING"
mkdir -p "$STAGING/include/SDL2"

if [ "$DRY_RUN" = false ]; then
    cp libSDL2.a libSDL2_test.a "$STAGING/"
    cp include/*.h "$STAGING/include/SDL2/"
    [ -f LICENSE ] && cp LICENSE "$STAGING/"
    [ -f README.md ] && cp README.md "$STAGING/"
    tar czf "$SDK_TARBALL" -C /tmp "$SDK_NAME"
    echo "  Created $SDK_TARBALL ($(wc -c < "$SDK_TARBALL") bytes)"
else
    echo "  [dry-run] Would create $SDK_TARBALL"
fi

# --- Package ports ---
ARTIFACTS=("$SDK_TARBALL")
PORTS=(julius ccleste chocolate-doom)

for port in "${PORTS[@]}"; do
    # Try common binary locations
    binary=""
    for candidate in "ports/$port/$port" "ports/$port/build/$port"; do
        if [ -f "$candidate" ]; then
            binary="$candidate"
            break
        fi
    done

    if [ -z "$binary" ]; then
        echo "SKIP: $port binary not found (not built?)"
        continue
    fi

    PORT_NAME="${port}-amigaos3-${TAG}"
    PORT_TARBALL="${PORT_NAME}.tar.gz"
    PORT_STAGING="/tmp/${PORT_NAME}"

    echo "Packaging port: $PORT_TARBALL"
    rm -rf "$PORT_STAGING"
    mkdir -p "$PORT_STAGING"

    if [ "$DRY_RUN" = false ]; then
        cp "$binary" "$PORT_STAGING/"
        tar czf "$PORT_TARBALL" -C /tmp "$PORT_NAME"
        echo "  Created $PORT_TARBALL ($(wc -c < "$PORT_TARBALL") bytes)"
        ARTIFACTS+=("$PORT_TARBALL")
    else
        echo "  [dry-run] Would create $PORT_TARBALL"
        ARTIFACTS+=("$PORT_TARBALL")
    fi
done

if [ "$PACKAGE_ONLY" = true ]; then
    echo "=== Package-only mode. Artifacts ready: ==="
    printf '  %s\n' "${ARTIFACTS[@]}"
    exit 0
fi

# --- Extract release notes from CHANGELOG ---
NOTES_FILE="/tmp/release-notes-${VERSION}.md"
# Extract notes between version header and next version header (macOS-safe)
awk "/^## \[${VERSION}\]/{found=1; next} /^## \[/{if(found) exit} found" CHANGELOG.md > "$NOTES_FILE"

echo "Release notes:"
cat "$NOTES_FILE"

# --- Tag and release ---
if [ "$DRY_RUN" = true ]; then
    echo "[dry-run] Would run: git tag -a $TAG -m 'Release $TAG'"
    echo "[dry-run] Would run: git push origin $TAG"
    echo "[dry-run] Would run: gh release create $TAG --title '$TAG' --notes-file $NOTES_FILE ${ARTIFACTS[*]}"
    echo "=== Dry run complete ==="
    exit 0
fi

echo "Creating tag $TAG..."
git tag -a "$TAG" -m "Release $TAG"
git push origin "$TAG"

echo "Creating GitHub release..."
gh release create "$TAG" \
    --title "$TAG" \
    --notes-file "$NOTES_FILE" \
    "${ARTIFACTS[@]}"

echo "=== Release $TAG published ==="
echo "https://github.com/bdgscotland/libSDL2-amigaos3/releases/tag/$TAG"

# Cleanup
rm -f "$NOTES_FILE"
rm -rf "/tmp/${SDK_NAME}" "/tmp/julius-amigaos3-${TAG}" "/tmp/ccleste-amigaos3-${TAG}" "/tmp/chocolate-doom-amigaos3-${TAG}"
