//
//  WMMaterialMeta.h
//  WMAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMActionServiceDefine.h"
#import "WMAdSDKDefines.h"
#import "WMAppInfo.h"
#import "WMDislikeWords.h"
#import "WMImage.h"

typedef NS_ENUM(NSInteger, WMInteractionType) {
    WMInteractionTypeCustorm = 0,
    WMInteractionTypeNO_INTERACTION = 1,    // 纯展示广告
    WMInteractionTypeURL = 2,               // 使用浏览器打开网页
    WMInteractionTypePage,                  // 应用内打开网页
    WMInteractionTypeDownload,              //下载应用
    WMInteractionTypePhone ,                // 拨打电话
    WMInteractionTypeMessage,               //发送短信
    WMInteractionTypeEmail                  //发邮件
};

typedef NS_ENUM(NSInteger, WMCreativeType) {
    WMCreativeTypeText,
    WMCreativeTypeImage,
    WMCreativeTypeGif,
    WMCreativeTypeHTML,
    WMCreativeTypeVideo,
    WMCreativeTypeText_ICON
};

typedef NS_ENUM(NSInteger, WMFeedADMode) {
    WMFeedADModeLargeImage = 2,
    WMFeedADModeSmallImage,
    WMFeedADModeGroupImage,
};

@interface WMMaterialMeta : NSObject <WMAd, WMActionPhoneModel, WMActionWebModel, NSCoding>

// 创意ID
@property (nonatomic, copy) NSString *AdID;
// 扩展字段，信息
@property (nonatomic, copy) NSString *extInfo;

// 广告支持的交互类型
@property (nonatomic, assign) WMInteractionType interactionType;

// 素材图片
@property (nonatomic, strong) NSArray<WMImage *> *imageAry;

// 图标图片
@property (nonatomic, strong) WMImage *icon;

// 创意的落地页URL
@property (nonatomic, copy) NSString *targetURL;

// 广告类型为电话时，电话号码必须
@property (nonatomic, copy) NSString *phone;

// 展现监测URL的列表
@property (nonatomic, copy) NSArray<NSString *> *show_urls;

// 点击监测的URL列表
@property (nonatomic, copy) NSArray<NSString *> *click_urls;

// 广告标题
@property (nonatomic, copy) NSString *AdTitle;

// 广告描述
@property (nonatomic, copy) NSString *AdDescription;

// 应用下载类广告信息
@property (nonatomic, strong) WMAppInfo *appInfo;


/**
 客户不喜欢广告，关闭时， 提示不喜欢原因
 */
@property (nonatomic, copy) NSArray<WMDislikeWords *> *filterWords;


// feed广告的展示类型，banner广告忽略
@property (nonatomic, assign) WMFeedADMode imageMode;

/**
 广告过期时间
 */
@property (nonatomic, assign) NSInteger expireTimestamp;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

