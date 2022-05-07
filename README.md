# Intro

Architecture is taken from https://github.com/getnamo/SocketIOClient-Unreal


# Description

- `EpinePlugin` - Plugin itself
- `EpineNative` - Wrapper for C++ SDK
- `EpineComponent` - Actor component that initializes and uses plugin

# Installation

1) Clone repository 

```
  git clone --recurse-submodules -j8  git@github.com:EpineCloud/EpinePlugin-Unreal.git
```

2) Follow dependency building steps described in `Source/ThirdPartyLibraries/EpineSDK/README.md`

3) Copy built dependency binaries into plugin's `Binaries`
```
mkdir -p Binaries/ThirdParty/EpineSDK/Mac
cp Source/ThirdPartyLibraries/EpineSDK/lib/sio/libsioclient.a Binaries/ThirdParty/EpineSDK/Mac
cp Source/ThirdPartyLibraries/EpineSDK/libepine-sdk.a Binaries/ThirdParty/EpineSDK/Mac
```

4) Include `EpinePlugin` into dependencies in project build file

Add to `ProjectName.Build.cs`
```
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EpinePlugin" });
PrivateDependencyModuleNames.AddRange(new string[] { "EpinePlugin" });
```


# TODO
- [ ] Automate dependency build and static library copy process
