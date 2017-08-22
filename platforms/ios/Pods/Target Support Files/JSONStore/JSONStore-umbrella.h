#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "JSONStoreFramework.h"
#import "JSONStore.h"
#import "JSONStoreOpenOptions.h"
#import "JSONStoreCollection.h"
#import "JSONStoreAddOptions.h"
#import "JSONStoreQueryPart.h"
#import "JSONStoreQueryOptions.h"
#import "JSONStoreConstants.h"
#import "JSONStoreSecurityManager.h"
#import "JSONStoreValidator.h"
#import "JSONStoreSecurityUtils.h"

FOUNDATION_EXPORT double JSONStoreVersionNumber;
FOUNDATION_EXPORT const unsigned char JSONStoreVersionString[];

