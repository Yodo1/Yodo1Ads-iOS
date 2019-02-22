#include <UIKit/UIKit.h>

/*! In-app message background image. */
@interface SwrveImage : NSObject

@property (nonatomic, retain) NSString* file;   /*!< Cached path of the image file on disk */
@property (atomic)            CGPoint center;   /*!< Center of the image */

@end
