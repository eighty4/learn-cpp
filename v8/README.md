
## Reading is fun

https://v8.dev/docs
https://v8.dev/docs/embed

## Module imports

v8::Isolate::SetHostImportModuleDynamicallyCallback
v8::Isolate::SetHostInitializeImportMetaObjectCallback
https://gist.github.com/surusek/4c05e4dcac6b82d18a1a28e6742fc23e

## Setup

Install [depot_tools](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html#_setting_up) to retrieve the v8 source from [Chromium's repository](https://chromium.googlesource.com/v8).

After `depot_tools` is on your path, run these commands to check out v8:

```
mkdir v8
cd v8
fetch v8
```

`fetch` will clone the repository into a subdirectory `v8`.

```
xcode-select -s /Applications/Xcode.app/Contents/Developer
```

```
cd v8
gclient sync
tools/dev/v8gen.py -b x64.debug x64.static.debug --no-goma -- v8_static_library=true v8_monolithic=true v8_use_external_startup_data=false is_component_build=false use_custom_libcxx=false
ninja -C out.gn/x64.static.debug
```

Remember to run `gclient sync` after a `git pull` or branch change.
