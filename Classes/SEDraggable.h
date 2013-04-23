//
//  SEDraggable.h
//  SEDraggable
//
//  Created by bryn austin bellomy <bryn@signals.io> on 10/23/11.
//  Copyright (c) 2012 robot bubble bath LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SEDraggableLocation.h"

@interface UIView (Helpr)
- (CGPoint) getCenterInWindowCoordinates;
@end

@class SEDraggableLocation, SEDraggable;

@protocol SEDraggableEventResponder <NSObject>
  @optional
      - (void) draggableObjectDidMove:(SEDraggable *)object;
      - (void) draggableObjectDidStopMoving:(SEDraggable *)object;

      - (void) draggableObject:(SEDraggable *)object didMoveWithinLocation:(SEDraggableLocation *)location;
      - (void) draggableObject:(SEDraggable *)object didStopMovingWithinLocation:(SEDraggableLocation *)location;

      - (void) draggableObject:(SEDraggable *)object willAskToEnterLocation:(SEDraggableLocation *)location withEntryMethod:(SEDraggableLocationEntryMethod)entryMethod;
      
      - (void) draggableObject:(SEDraggable *)object finishedEnteringLocation:(SEDraggableLocation *)location withEntryMethod:(SEDraggableLocationEntryMethod)entryMethod;
      - (void) draggableObject:(SEDraggable *)object failedToEnterLocation:(SEDraggableLocation *)location withEntryMethod:(SEDraggableLocationEntryMethod)entryMethod;

      - (BOOL) draggableObject:(SEDraggable *)object shouldAskToEnterLocation:(SEDraggableLocation *)location withEntryMethod:(SEDraggableLocationEntryMethod)entryMethod;
@end

// keyed archiving constants
#define kPAN_GESTURE_RECOGNIZER_KEY 			@"panGestureRecognizer"
#define kCURRENT_LOCATION_KEY                   @"currentLocation"
#define kHOME_LOCATION_KEY                      @"homeLocation"
#define kPREVIOUS_LOCATION_KEY                  @"previousLocation"
#define kDROPPABLE_LOCATIONS_KEY                @"droppableLocations"
#define kDELEGATE_KEY                           @"delegate"
#define kSHOULD_SNAP_BACK_TO_HOME_LOCATION_KEY 	@"shouldSnapBackToHomeLocation"
#define kSHOULD_SNAP_BACK_TO_DRAG_ORIGIN_KEY    @"shouldSnapBackToDragOrigin"
#define kFIRST_X_KEY                            @"firstX"
#define kFIRST_Y_KEY                            @"firstY"

@interface SEDraggable : UIImageView <SEDraggableLocationClient, UIGestureRecognizerDelegate, NSCoding>

@property (nonatomic, strong) UIPanGestureRecognizer *panGestureRecognizer;
@property (nonatomic, weak) SEDraggableLocation *currentLocation;
@property (nonatomic, weak) SEDraggableLocation *homeLocation;

@property (nonatomic, weak) SEDraggableLocation *previousLocation;
@property (nonatomic, strong) NSMutableSet *droppableLocations;
@property (nonatomic, weak) id <SEDraggableEventResponder> delegate;
@property (nonatomic, assign) BOOL shouldSnapBackToHomeLocation;
@property (nonatomic, assign) BOOL shouldSnapBackToDragOrigin;
@property (nonatomic, readonly) CGFloat firstX;
@property (nonatomic, readonly) CGFloat firstY;

- (void) addAllowedDropLocation:(SEDraggableLocation *)location;
- (void) snapCenterToPoint:(CGPoint)point animated:(BOOL)animated completion:(void (^)(BOOL))completionBlock;

- (void) askToDropIntoLocation:(SEDraggableLocation *)location animated:(BOOL)animated;
- (void) askToSnapBackToLocation:(SEDraggableLocation *)location animated:(BOOL)animated;


@end


