//
//  RZCentralManager+Private.h
//  UMTSDK
//
//  Created by Brian King on 7/27/15.
//  Copyright (c) 2015 Raizlabs. All rights reserved.
//

#import "RZBCentralManager.h"
#import "RZBCommandDispatch.h"
#import "RZBPeripheralState.h"
#import "RZBCentralManagerState.h"

@interface RZBCentralManager () <CBCentralManagerDelegate, CBPeripheralDelegate>

/**
 * Internal initializer for specifying alternate bluetooth classes.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier queue:(dispatch_queue_t)queue centralClass:(Class)centralClass;

@property (strong, nonatomic, readonly) RZBCommandDispatch *dispatch;
@property (strong, nonatomic, readonly) CBCentralManager *centralManager;
@property (strong, nonatomic, readonly) RZBCentralManagerState *managerState;

@property (nonatomic, copy) RZBScanBlock activeScanBlock;

/**
 * Obtain a connected peripheral. If the result is nil, a connect
 * command will be made, and the triggeredByCommand will be made dependent
 * on the connect command completing.
 */
- (CBPeripheral *)connectedPeripheralForUUID:(NSUUID *)peripheralUUID
                          triggeredByCommand:(RZBCommand *)triggeringCommand;

/**
 * Obtain a service. If the result is nil, a service discover
 * command will be made, and the triggeredByCommand will be made dependent
 * on the discover command completing.
 */
- (CBService *)serviceForUUID:(CBUUID *)serviceUUID
                 onPeripheral:(CBPeripheral *)peripheral
           triggeredByCommand:(RZBCommand *)triggeringCommand;

/**
 * Obtain a characteristic. If the result is nil, a characteristic discover
 * command will be made, and the triggeredByCommand will be made dependent
 * on the discover command completing.
 */
- (CBCharacteristic *)characteristicForUUID:(CBUUID *)characteristicUUID
                                  onService:(CBService *)service
                         triggeredByCommand:(RZBCommand *)triggeringCommand;

- (CBService *)serviceForUUID:(CBUUID *)serviceUUID
                 onPeripheral:(CBPeripheral *)peripheral;

@end
