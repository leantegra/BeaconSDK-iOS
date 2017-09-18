//
//  LSRangingEnums.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/5/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Describes relative distance between WiBeat and the device.
 */
typedef NS_ENUM(NSInteger, LSProximityZone) {
    /*!
     * Unknown distance to WiBeat.
     */
    UNKNOWN,
    /*!
     * Distance to WiBeat is not more than 0.5m.
     */
    IMMEDIATE,
    /*!
     * Distance to WiBeat is not more than 3.0m.
     */
    NEAR,
    /*!
     * Distance to WiBeat is more than 3.0m.
     */
    FAR
};

/**
 * Type enum describes all possible advertising frames of the WiBeat.
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
     * Eddystone (TLM) frame format
     */
    FRAME_TYPE_EDDYSTONE_TLM,
    /**
     * Eddystone (UID) frame format
     */
    FRAME_TYPE_EDDYSTONE_UID,
    /**
     * Eddystone (EID) frame format
     */
    FRAME_TYPE_EDDYSTONE_EID,
    /**
     * Location Tag frame format.
     */
    FRAME_TYPE_TAG
};

