# PowerMote SDK v 1.0.0 for iOS #

The PowerMote SDK for iOS is a library that allows interaction with [PowerMotes](http://leantegra.com/pm).
It works with iOS 8 or above and requires Bluetooth Low Energy support.

Features:
- Based on Apple Core Location and Apple Core Bluetooth Frameworks;
- PowerMote management: connect\disconnect, read\write all info from nearby device;
- PowerMote ranging: scanning for nearby devices, filtering by specified properties, distance to device (IMMEDIATE, NEAR, FAR zones);
- PowerMote monitoring: monitors Enter\Exit events for predefined regions that can be defined by multiple rules (UUID, distance, zone, Major, Minor etc.)

## Installation

### Manual installation

1. Add [LeantegraSDK.framework](https://github.com/leantegra/iOSPowerMoteSDK/blob/master/PowerMoteSDK/LeantegraSDK.framework) into XCode project; 
2. Add Apple's CoreLocation and Apple's CoreBlueooth frameworks into XCode project;
3. For PowerMote Monitoring feature, add [NSLocationAlwaysUsageDescription](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18) property key;
4. For PowerMote Monitoring feature, enable "Location updates" checkbox in XCode target settings -- TARGETS/Capabilities/Background Modes.

## How to use

### Documentation

Apple Docs for PowerMote SDK you can find [here](http://leantegra.github.io/iOSPowerMoteSDK/AppleDocs/).

### Demo Applications

Demo applications you can find [here](https://github.com/leantegra/iOSPowerMoteSDK/tree/master/Demos).

