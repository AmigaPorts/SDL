# CPM Package Lock
# This file should be committed to version control.

CPMDeclarePackage(CMakeAmigaCommon
  GIT_TAG 1.0.7
  GITHUB_REPOSITORY AmigaPorts/cmake-amiga-common-library
)

CPMDeclarePackage(SFDC
  GIT_TAG a4c7443b0865c06c8406cc3d92023c4706a472f0
  GITHUB_REPOSITORY AmigaPorts/sfdc
  DOWNLOAD_ONLY YES
)
