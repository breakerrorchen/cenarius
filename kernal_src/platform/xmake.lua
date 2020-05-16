
if is_plat("windows") then
    includes("windows/xmake.lua")
elseif is_plat("linux") then
    includes("linux/xmake.lua")
elseif is_plat("macosx") then
    includes("macosx/xmake.lua")
elseif is_plat("android") then
    includes("android/xmake.lua")
elseif is_plat("iphoneos") then
    includes("iphoneos/xmake.lua")
end