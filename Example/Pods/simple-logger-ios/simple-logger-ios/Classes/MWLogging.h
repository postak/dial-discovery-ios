//  Copyright 2015 British Broadcasting Corporation
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.


/**
 * This is an extension of this logger: https://github.com/MikeWeller/MWLogging/blob/master/MWLogging.h
 */

/*
 SimpleLogger. Simple wrapper macros/functions around ASL (Apple System
 Log)

 We support a compile-time log level through
 MW_COMPILE_TIME_LOG_LEVEL. This will turn the associated log calls
 into NOPs.

 The log levels are the constants defined in asl.h:

 #define ASL_LEVEL_EMERG   0
 #define ASL_LEVEL_ALERT   1
 #define ASL_LEVEL_CRIT    2
 #define ASL_LEVEL_ERR     3
 #define ASL_LEVEL_WARNING 4
 #define ASL_LEVEL_NOTICE  5
 #define ASL_LEVEL_INFO    6
 #define ASL_LEVEL_DEBUG   7

 For a description of when to use each level, see here:

 http://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPSystemStartup/Chapters/LoggingErrorsAndWarnings.html#//apple_ref/doc/uid/10000172i-SW8-SW1

 Emergency (level 0) - The highest priority, usually reserved for
                       catastrophic failures and reboot notices.

 Alert (level 1)     - A serious failure in a key system.

 Critical (level 2)  - A failure in a key system.

 Error (level 3)     - Something has failed.

 Warning (level 4)   - Something is amiss and might fail if not
                       corrected.

 Notice (level 5)    - Things of moderate interest to the user or
                       administrator.

 Info (level 6)      - The lowest priority that you would normally log, and
                       purely informational in nature.

 Debug (level 7)     - The lowest priority, and normally not logged except
                       for messages from the kernel.


 Note that by default the iOS syslog/console will only record items up
 to level ASL_LEVEL_NOTICE.

 */


#import <Foundation/Foundation.h>

// By default, in non-debug mode we want to disable any logging
// statements except NOTICE and above.
#ifndef MW_COMPILE_TIME_LOG_LEVEL
	#ifdef NDEBUG
		#define MW_COMPILE_TIME_LOG_LEVEL ASL_LEVEL_NOTICE
	#else
		#define MW_COMPILE_TIME_LOG_LEVEL ASL_LEVEL_DEBUG
	#endif
#endif



#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_EMERG
/**
 * Log a message at level ASL_LEVEL_EMERG
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogEmergency(NSString *format, ...);
#else
#define MWLogEmergency(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_ALERT
/**
 * Log a message at level ASL_LEVEL_ALERT
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogAlert(NSString *format, ...);
#else
#define MWLogAlert(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_CRIT
/**
 * Log a message at level ASL_LEVEL_CRIT
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogCritical(NSString *format, ...);
#else
#define MWLogCritical(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_ERR
/**
 * Log a message at level ASL_LEVEL_ERR
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogError(NSString *format, ...);
#else
#define MWLogError(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_WARNING
/**
 * Log a message at level ASL_LEVEL_WARNING
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogWarning(NSString *format, ...);
#else
#define MWLogWarning(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_NOTICE
/**
 * Log a message at level ASL_LEVEL_NOTICE
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogNotice(NSString *format, ...);
#else
#define MWLogNotice(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_INFO
/**
 * Log a message at level ASL_LEVEL_INFO
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogInfo(NSString *format, ...);
#else
#define MWLogInfo(...)
#endif

#if MW_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_DEBUG
/**
 * Log a message at level ASL_LEVEL_DEBUG
 *
 * @param format String, including formatting as per [NSString initWithFormat:]
 * @param ... remaining arguments as required by any formatting codes in the format string.
 */
void MWLogDebug(NSString *format, ...);
#else
#define MWLogDebug(...)
#endif

