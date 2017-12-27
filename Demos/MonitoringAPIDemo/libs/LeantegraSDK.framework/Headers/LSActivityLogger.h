//
//  LSActivityLogger.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 5/12/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Directory in NSDocumentDirectory, where all log files are stored.
 */
extern NSString *const kLSLogsDirectory;

/**
 * Stamp for a file, line number, and time, when this macto is called from.
 */
#define LSPlaceStamp() [NSString stringWithFormat:@"%@ %s (Line %d):", LSDateStamp(), __PRETTY_FUNCTION__, __LINE__]

/**
 * Simple logs a message into a log file. <code>LSPlaceStamp()</code> is added to each message automatically.
 * Has no effect, if +[LSActivityLogger startLog] was not called
 */
#define LSLog(format, ...) LSStampedLog(LSDateStamp(), format, ##__VA_ARGS__)

/**
 * Logs the error message in a log file. <code>LSPlaceStamp()</code> and [ERROR]: are added to each message automatically.
 * Has no effect, if +[LSActivityLogger startLog] was not called
 */
#define LSErrorLog(format, ...) LSStampedLog(LSPlaceStamp(), @"[ERROR]: " format, ##__VA_ARGS__)

/**
 * Logs the networking related message in a log file. <code>LSDateStamp()</code> and [NET]: are added to each message automatically.
 * Has no effect, if +[LSActivityLogger startLog] was not called
 */
#define LSNetworkLog(format, ...) LSStampedLog(LSDateStamp(), @"[NET]: " format, ##__VA_ARGS__)

/**
 * Logs the Data Base related message in a log file. <code>LSDateStamp()</code> and [DB]: are added to each message automatically.
 * Has no effect, if +[LSActivityLogger startLog] was not called
 */
#define LSDBLog(format, ...) LSStampedLog(LSDateStamp(), @"[DB]: " format, ##__VA_ARGS__)

/**
 * Simple logs a message into a log file.
 * Has no effect, if <code>+[LSActivityLogger startLog]</code> was not called
 */
void LSStampedLog(NSString *stamp, NSString *format, ...);

/**
 * Saves given data to LSLog location with a giving filename. Logged data is stored in <code>kLSLogsDirectory</code>
 * @param data - data to save
 * @param filename - name (with file extension) for the file to be stored
 */
void LSLogData(NSData *data, NSString *filename);

/**
 * Stamp for time with msec.
 */
NSString *LSDateStamp(void);

@interface LSActivityLogger : NSObject

/**
 * Maximum log file size in bytes.
 * @param maxFileSize - If no value or 0 is provided, 2097152 (2 mb) will be used as default value
 */
+ (void)setMaxLogFileSize:(unsigned long long)maxFileSize;

/**
 * Current maximum of log file size in bytes.
 */
+ (unsigned long long)maxLogFileSize;

/**
 * Count of stored log files.
 * @param maxFilesCount - If no value or 0 is provided, 5 will be used as default value.
 * All logs are stored in files: "syslogX.log", where X - is an index of log file. The newest logs files have the smallest index, so the most recent logs are stored in "syslog0.log".
 */
+ (void)setMaxLogFilesCount:(NSUInteger)maxFilesCount;

/**
 * Current count of stored log files.
 */
+ (NSUInteger)maxLogFilesCount;

/**
 * Starts the logging. Since this called, messages passed via <code>LSLog()</code>, <code>LSErrorLog()</code>, <code>LSNetworkLog()</code>, <code>LSDBLog()</code>, <code>LSStampedLog()</code>, <code>+[LSActivityLogger logFormatString:arguments:stamp:]</code> will be stored in log files.
 * All logs are stored in files: "syslogX.log", where X - is an index of log file. The newest logs files have the smallest index, so the most recent logs are stored in "syslog0.log".
 */
+ (void)startLog;

/**
 * Starts the logging. Since this called, messages passed via <code>LSLog()</code>, <code>LSErrorLog()</code>, <code>LSNetworkLog()</code>, <code>LSDBLog()</code>, <code>LSStampedLog()</code>, <code>+[LSActivityLogger logFormatString:arguments:stamp:]</code> will have no effect.
 */
+ (void)stopLog;

/**
 * Idicates, if logging did started.
 */
+ (BOOL)loggingDidStart;

/**
 * Logs a message into a log file.
 * Has no effect, if +[LSActivityLogger startLog] was not called. It's recommended to use one of the following wrappers:<code>LSLog()</code>, <code>LSErrorLog()</code>, <code>LSNetworkLog()</code>, <code>LSDBLog()</code>, <code>LSStampedLog()</code> instead of direct call of this method.
 * @param format - NSString format to be logged
 * @param argList - lost of format string arguments
 * @param stamp - NSString stamp to be attached at the begining of log message
 */
+ (void)logFormatString:(NSString *)format arguments:(va_list)argList stamp:(NSString *)stamp;

/**
 * Saves given data to LSLog location with a giving filename. Function-like API is also available - use LSLogData().
 * @param data - data to save
 * @param filename - name (with file extension) for the file to be stored
 */
+ (void)logData:(NSData *)data name:(NSString *)filename;

@end
