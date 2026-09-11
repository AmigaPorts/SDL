// Get CGWindowID or window bounds for a process by PID
// Usage: get-window-id <pid>           -> prints CGWindowID
//        get-window-id --bounds <pid>  -> prints "x,y,w,h" for screencapture -R
import CoreGraphics
import Foundation

let args = CommandLine.arguments
var boundsMode = false
var pid = 0

if args.count == 3, args[1] == "--bounds", let p = Int(args[2]) {
    boundsMode = true
    pid = p
} else if args.count == 2, let p = Int(args[1]) {
    pid = p
} else {
    exit(1)
}

let list = CGWindowListCopyWindowInfo(.optionAll, kCGNullWindowID) as! [[String: Any]]
for w in list {
    if let wpid = w[kCGWindowOwnerPID as String] as? Int, wpid == pid,
       let layer = w[kCGWindowLayer as String] as? Int, layer == 0,
       let wnum = w[kCGWindowNumber as String] as? Int {
        if boundsMode {
            if let b = w[kCGWindowBounds as String] as? [String: CGFloat] {
                let x = Int(b["X"]!), y = Int(b["Y"]!), w = Int(b["Width"]!), h = Int(b["Height"]!)
                print("\(x),\(y),\(w),\(h)")
                exit(0)
            }
        } else {
            print(wnum)
            exit(0)
        }
    }
}
exit(1)
