# WiBeat SDK for iOS #

The WiBeat SDK for iOS is a library that allows interaction with [WiBeats](http://leantegra.com/wibeat-ble-beacon).
It works with iOS 8 or above and requires Bluetooth Low Energy support.

Features:
- Based on Apple Core Location and Apple Core Bluetooth Frameworks;
- WiBeat management: connect\disconnect, read\write all info from nearby device;
- WiBeat ranging: scanning for nearby devices, filtering by specified properties, distance to device (IMMEDIATE, NEAR, FAR zones);
- WiBeat monitoring: monitors Enter\Exit events for predefined regions that can be defined by multiple rules (UUID, distance, zone, Major, Minor etc.);
- Integration with Leantegra CMS (notifications, multi-rules, analytics).

## Installation

### Manual installation

1. Add [LeantegraSDK.framework](https://github.com/leantegra/iOSWiBeatSDK/blob/master/WiBeatSDK/LeantegraSDK.framework) into XCode project; 
2. Add Apple's CoreLocation and Apple's CoreBlueooth frameworks into XCode project;
3. For WiBeat Monitoring feature, add [NSLocationAlwaysUsageDescription](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18) property key;
4. For WiBeat Monitoring feature, enable "Location updates" checkbox in XCode target settings -- TARGETS/Capabilities/Background Modes.

## How to use

### Documentation

Apple Docs for WiBeat SDK you can find [here](http://leantegra.github.io/iOSWiBeatSDK/AppleDocs/).

### Demo Applications

Demo applications you can find [here](https://github.com/leantegra/iOSWiBeatSDK/tree/master/Demos).

### Changelog

The list of changes in WiBeat SDK for iOS located in [CHANGELOG](https://github.com/leantegra/iOSWiBeatSDK/blob/master/CHANGELOG.md).
