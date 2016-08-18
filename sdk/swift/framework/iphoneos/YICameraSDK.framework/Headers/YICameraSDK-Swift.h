// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class ActionCameraListener;
@protocol DispatchQueue;


/// Present an YI action camera.
///
/// This class presents an YI action camera. App can invoke its functions to control the camera.
/// Like start recording, stop recording, take picture, read settings, set settings, etc. Before
/// operating an camera, App need invoke <code>ActionCamera.connect(connectionString:)
/// </code> to connect to the camera.
/// After connect success (<code>ActionCameraListener.onConnected()
/// </code> will be invoked), app can invoke other functions.
/// Whenever app wants to disconnect from the camera, app can invoke <code>ActionCamera.disconnect()
/// </code>.
///
/// Any <code>success
/// </code> or <code>fail
/// </code> callback in commands are optional parameter. If you don't care command
/// execution result, you can pass <code>nil
/// </code>.
SWIFT_CLASS("_TtC11YICameraSDK12ActionCamera")
@interface ActionCamera : NSObject

/// Constructor of ActionCamera.
///
/// When app creates an ActionCamera object, app need specify a listener which will receive the
/// camera notifications and a message queue which will be used to dispatch the notification.
/// Recommend app uses the same message queue as UI thread using. So that all notifications will
/// be passed in UI thread and app can update UI directly in the callback of notifications.
///
/// \param listener The listener will be used to receive notification from the camera.
///
/// \param workThreadQueue The message queue will be used to dispatch camera notifications.
- (nonnull instancetype)initWithListener:(ActionCameraListener * _Nonnull)listener dispatchQueue:(id <DispatchQueue> _Nonnull)dispatchQueue OBJC_DESIGNATED_INITIALIZER;

/// Connect to a YI action camera.
///
/// Invoke this function to connect to a YI action camera. Param <code>connectionString
/// </code> represents
/// the address of the remote camera. Format is:
///
/// <code>tcp:<ip address>:<port>
/// 
/// </code>
/// If the camera has been connected or the previous connect operation hasn't been finished.
/// Nothing will happen. Otherwise connect operation will be executed asynchronously. If success,
/// <code>ActionCameraListener.onConnected()
/// </code> callback will be invoked. If fail,
/// <code>ActionCameraListener.onClosed(error:)
/// </code> callback will be invoked and parameter <code>error
/// </code>
/// will be set.
- (void)connectWithConnectionString:(NSString * _Nonnull)connectionString;

/// Disconnect from YI action camera.
///
/// Invoke this function to disconnect from a YI action camera. This function will return
/// immediately and the disconnect operation will be executed asynchronously. All pending
/// commands will be cancelled (the <code>fail
/// </code> callback of the command will be invoked and the
/// code of <code>error
/// </code> parameter will be set to <code>ErrorCode.Cancelled
/// </code>). At the end,
/// <code>ActionCameraListener.onClosed(error:)
/// </code> callback will be invoked and <code>error
/// </code> parameter
/// will be set to <code>nil
/// </code>.
- (void)disconnect;
@end

@class Error;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Take a picture on camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)takeCaptureWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

@class NSDate;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Set datetime to camera.
///
/// \param datetime The datetime you want to set to camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setDateTimeWithDatetime:(NSDate * _Nonnull)datetime success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

enum SystemMode : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Set camera system mode.
///
/// \param mode System mode supported by YI action camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setSystemModeWithMode:(enum SystemMode)mode success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

@class ActionCameraSetting;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get camera settings.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// the settings of camera.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getSettingWithSuccess:(void (^ _Nullable)(ActionCameraSetting * _Nonnull))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Stop recording on camera.
///
/// \param success If command executes success, this callback wil be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)stopRecordingWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Start recording immediately.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)startRecordingWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Start recording at specific time.
///
/// \param hour Start recording at this hour.
///
/// \param minute Start recording at this minute.
///
/// \param second Start recording at this second.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)startRecordingWithHour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end



/// Define the callback to receive camera notifications.
SWIFT_CLASS("_TtC11YICameraSDK20ActionCameraListener")
@interface ActionCameraListener : NSObject

/// When ActionCamera.connect() success, this callback will be invoked.
- (void)onConnected;

/// When the connection to camera is closed, this callback will be invoked.
///
/// \param error If the connection is closed due to any error, this parameter will be set.
/// If it is <code>nil
/// </code>, means the connection is closed by app.
- (void)onClosedWithError:(Error * _Nullable)error;

/// When recording is started on camera, this callback will be invoked.
- (void)onRecordStarted;

/// When recording is stopped on camera, this callback will be invoked.
- (void)onRecordStopped;

/// When capture is started on camera, this callback will be invoked.
- (void)onCaptureStarted;

/// When capture is stopped on camera, this callback will be invoked.
- (void)onCaptureStopped;

/// When video finder started, this callback will be invoked. After received this event, you can start play video stream vi rtsp protocol.
- (void)onVideoFinderStarted;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

enum Status : NSInteger;
enum VideoStandard : NSInteger;
enum VideoResolution : NSInteger;
enum Quality : NSInteger;
enum PhotoSize : NSInteger;


/// Define the camera settings.
SWIFT_CLASS("_TtC11YICameraSDK19ActionCameraSetting")
@interface ActionCameraSetting : NSObject

/// Current status.
@property (nonatomic) enum Status status;

/// Current datetime of camera.
@property (nonatomic, strong) NSDate * _Nullable clock;

/// Current software version.
@property (nonatomic, copy) NSString * _Nullable softwareVersion;

/// Current hardware version.
@property (nonatomic, copy) NSString * _Nullable hardwareVersion;

/// Serial number of camera.
@property (nonatomic, copy) NSString * _Nullable serialNumber;

/// Product name of camera.
@property (nonatomic, copy) NSString * _Nullable productName;

/// Current mode of camera.
@property (nonatomic) enum SystemMode systemMode;

/// Current video standard.
@property (nonatomic) enum VideoStandard videoStandard;

/// Current video resolution.
@property (nonatomic) enum VideoResolution videoResolution;

/// Current video quality.
@property (nonatomic) enum Quality videoQuality;

/// Current picture resolution.
@property (nonatomic) enum PhotoSize photoSize;
@end



/// Define the interface of message loop.
///
/// App need implement this interface and runs a message loop to process the message/task one by one.
/// All callback will be invoked from this queue.
SWIFT_PROTOCOL("_TtP11YICameraSDK13DispatchQueue_")
@protocol DispatchQueue

/// Put a task to the queue.
///
/// <em>Note: This method must be thread safe.</em>
///
/// \param task The task will be executed from the message loop.
- (void)dispatchWithTask:(void (^ _Nonnull)(void))task;
@end



/// Represent the error.
SWIFT_CLASS("_TtC11YICameraSDK5Error")
@interface Error : NSObject

/// Get the error code.
- (uint32_t)getCode;

/// Get the sub error.
- (Error * _Nullable)getSubError;

/// Get the detail information of error.
- (NSString * _Nullable)getDetail;
@end



/// Define the error code of an error object.
SWIFT_CLASS("_TtC11YICameraSDK9ErrorCode")
@interface ErrorCode : NSObject

/// Success, not an error.
+ (uint32_t)Success;

/// Operation has been cancelled by the user.
+ (uint32_t)Cancelled;

/// State is invalid.
+ (uint32_t)InvalidState;

/// An IOException is raised.
+ (uint32_t)IOException;

/// Parameter is invalid.
+ (uint32_t)InvalidParameter;

/// Operation is not supported.
+ (uint32_t)NotSupported;

/// The response format of the camera is invalid.
+ (uint32_t)InvalidResponse;

/// Command executes failed.
+ (uint32_t)CommandFailed;

/// The format is invalid.
+ (uint32_t)InvalidFormat;

/// Requirements are not meet.
+ (uint32_t)PreConditionFailed;

/// Timeout.
+ (uint32_t)Timeout;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



/// Define the log interface.
///
/// App can write a subclass inherited from this class to supply log functionality.
SWIFT_CLASS("_TtC11YICameraSDK6Logger")
@interface Logger : NSObject

/// Output verbose level log.
///
/// \param message The message will be outputted at verbose level.
- (void)verboseWithMessage:(NSString * _Nonnull)message;

/// Output info level log.
///
/// \param message The message will be outputted at info level.
- (void)infoWithMessage:(NSString * _Nonnull)message;

/// Output warning level log.
///
/// \param message The message will be outputted at warning level.
- (void)warningWithMessage:(NSString * _Nonnull)message;

/// Output error level log.
///
/// \param message The message will be outputted at error level.
- (void)errorWithMessage:(NSString * _Nonnull)message;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Picture resolution supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, PhotoSize) {

/// Unknown
  PhotoSizeUnknown = 0,

/// Photo size is 12MP (4000x3000 4:3) fov:w
  PhotoSizep_12MP_4000x3000_4x3_w = 1,

/// Photo size is 7MP (3008x2256 4:3) fov:w
  PhotoSizep_7MP_3008x2256_4x3_w = 2,

/// Photo size is 7MP (3008x2256 4:3) fov:m
  PhotoSizep_7MP_3008x2256_4x3_m = 3,

/// Photo size is 5MP (2560x1920 4:3) fov:m
  PhotoSizep_5MP_2560x1920_4x3_m = 4,

/// Photo size is 8MP (3840x2160 16:9) fov:w
  PhotoSizep_8MP_3840x2160_16x9_w = 5,
};



/// This class will be used to initialize/uninitialize the whole SDK platform.
SWIFT_CLASS("_TtC11YICameraSDK8Platform")
@interface Platform : NSObject

/// Initialize SDK platform.
///
/// This function should only be invoked once at the app startup. App shouldn't invoke any
/// functions before invoking this function.
///
/// \param logger The log interface (app need implements this interface) used by the whole
/// SDK platform. Pass <code>nil
/// </code> will turn off the log.
+ (void)initializeWithLogger:(Logger * _Nonnull)logger;

/// Uninitialize SDK platform.
///
/// This function should only be invoked once at the app ended. App shouldn't invoke any
/// functions after invoking this function.
+ (void)uninitialize;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Quality supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, Quality) {

/// Unknown.
  QualityUnknown = 0,

/// Low quality.
  QualityLow = 1,

/// Middle quality.
  QualityMiddle = 2,

/// High quality.
  QualityHigh = 3,
};


/// Camera status.
typedef SWIFT_ENUM(NSInteger, Status) {

/// Unknown.
  StatusUnknown = 0,

/// Camera is idle.
  StatusIdle = 1,
};


/// Camera mode supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, SystemMode) {

/// Unknown.
  SystemModeUnknown = 0,

/// Video mode.
  SystemModeRecord = 1,

/// Picture mode.
  SystemModeCapture = 2,
};


/// Video resolution supported by YICamera.
typedef SWIFT_ENUM(NSInteger, VideoResolution) {

/// Unknown
  VideoResolutionUnknown = 0,

/// Resolution is 3840x1260 30P 16:9.
  VideoResolutionv_3840x2160_30p_16x9 = 1,

/// Resolution is 3840x2160 30P 16:9 super.
  VideoResolutionv_3840x2160_30p_16x9_super = 2,

/// Resolution is 2560x1920 30P 4:3.
  VideoResolutionv_2560x1920_30p_4x3 = 3,

/// Resolution is 1920x1440 60P 4:3.
  VideoResolutionv_1920x1440_60p_4x3 = 4,

/// Resolution is 1920x1440 30P 4:3.
  VideoResolutionv_1920x1440_30p_4x3 = 5,

/// Resolution is 1920x1080 120P 16:9.
  VideoResolutionv_1920x1080_120p_16x9 = 6,

/// Resolution is 1920x1080 120P 16:9 super.
  VideoResolutionv_1920x1080_120p_16x9_super = 7,

/// Resolution is 1920x1080 60P 16:9.
  VideoResolutionv_1920x1080_60p_16x9 = 8,

/// Resolution is 1920x1080 60P 16:9 super.
  VideoResolutionv_1920x1080_60p_16x9_super = 9,

/// Resolution is 1920x1080 30P 16:9.
  VideoResolutionv_1920x1080_30p_16x9 = 10,

/// Resolution is 1920x1080 30P 16:9 super.
  VideoResolutionv_1920x1080_30p_16x9_super = 11,

/// Resolution is 1280x960 120P 4:3.
  VideoResolutionv_1280x960_120p_4x3 = 12,

/// Resolution is 1280x960 60P 4:3.
  VideoResolutionv_1280x960_60P_4x3 = 13,

/// Resolution is 1280x720 240P 16:9.
  VideoResolutionv_1280x720_240p_16x9 = 14,

/// Resolution is 1280x720 120P 16:9 super.
  VideoResolutionv_1280x720_120p_16x9_super = 15,

/// Resolution is 1280x720 60P 16:9 super.
  VideoResolutionv_1280x720_60p_16x9_super = 16,

/// Resolution is 840x480 240P 16:9.
  VideoResolutionv_840x480_120p_16x9 = 17,
};


/// Video standard supported by YICamera.
typedef SWIFT_ENUM(NSInteger, VideoStandard) {

/// Unknown
  VideoStandardUnknown = 0,

/// PAL standard
  VideoStandardPAL = 1,

/// NTSC standard
  VideoStandardNTSC = 2,
};

#pragma clang diagnostic pop
