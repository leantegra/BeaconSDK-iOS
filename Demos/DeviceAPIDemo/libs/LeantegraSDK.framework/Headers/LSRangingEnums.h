//
//  LSRangingEnums.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/5/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Describes relative distance between PowerMote and the device.
 */
typedef NS_ENUM(NSInteger, LSProximityZone) {
    /*!
     * Unknown distance to PowerMote.
     */
    UNKNOWN,
    /*!
     * Distance to PowerMote is not more than 0.5m.
     */
    IMMEDIATE,
    /*!
     * Distance to PowerMote is not more than 3.0m.
     */
    NEAR,
    /*!
     * Distance to PowerMote is more than 3.0m.
     */
    FAR
};

/**
 * Type enum describes all possible advertising frames of the PowerMote.
 */
typedef NS_ENUM(NSInteger, LSFrameType){
    /**
     * iBeacon frame format.
     */
    FRAME_TYPE_I_BEACON,
    /**
     * Eddystone(URL) frame format.
     */
    FRAME_TYPE_EDDYSTONE_URL,
    /**
     * Location Tag frame format.
     */
    FRAME_TYPE_TAG
};

