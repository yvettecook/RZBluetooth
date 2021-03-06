//
//  RZBSimulatedCentral.h
//  RZBluetooth
//
//  Created by Brian King on 7/31/15.
//  Copyright (c) 2015 Raizlabs. All rights reserved.
//

#import "RZBMockCentralManager.h"

@class RZBMockPeripheralManager;
@class RZBSimulatedConnection;

@interface RZBSimulatedCentral : NSObject <RZBMockCentralManagerDelegate>

- (void)addSimulatedDeviceWithIdentifier:(NSUUID *)peripheralUUID peripheralManager:(RZBMockPeripheralManager *)peripheralManager;

- (void)removeSimulatedDevice:(NSUUID *)peripheralUUID;

- (RZBSimulatedConnection *)connectionForIdentifier:(NSUUID *)identifier;

@property (assign, nonatomic) NSUInteger maximumUpdateValueLength;

@end
