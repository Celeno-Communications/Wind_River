/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "external/freertos_kernel/FreeRTOS_wrap.h"
#include "stdio.h"

#ifndef FREE_RTOS_BLINKY_DEMO
#  define FREE_RTOS_BLINKY_DEMO 1
#endif

#if FREE_RTOS_BLINKY_DEMO
// copied from https://github.com/FreeRTOS/FreeRTOS/blob/main/FreeRTOS/Demo/Posix_GCC/main_blinky.c

//#include <stdio.h>
//#include <pthread.h>

/* Kernel includes. */
#  include "FreeRTOS.h"
#  include "task.h"
#  include "timers.h"
#  include "semphr.h"

/* Local includes. */
//#include "console.h"

/* Priorities at which the tasks are created. */
#  define mainQUEUE_RECEIVE_TASK_PRIORITY (tskIDLE_PRIORITY + 2)
#  define mainQUEUE_SEND_TASK_PRIORITY (tskIDLE_PRIORITY + 1)

/* The rate at which data is sent to the queue.  The times are converted from
 * milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#  define mainTASK_SEND_FREQUENCY_MS pdMS_TO_TICKS(200UL)
#  define mainTIMER_SEND_FREQUENCY_MS pdMS_TO_TICKS(2000UL)

/* The number of items the queue can hold at once. */
#  define mainQUEUE_LENGTH (2)

/* The values sent to the queue receive task from the queue send task and the
 * queue send software timer respectively. */
#  define mainVALUE_SENT_FROM_TASK (100UL)
#  define mainVALUE_SENT_FROM_TIMER (200UL)

/*
 * The tasks as described in the comments at the top of this file.
 */
static void prvQueueReceiveTask(void* pvParameters);
static void prvQueueSendTask(void* pvParameters);

/*
 * The callback function executed when the software timer expires.
 */
static void prvQueueSendTimerCallback(TimerHandle_t xTimerHandle);

/*-----------------------------------------------------------*/

/* The queue used by both tasks. */
static QueueHandle_t xQueue = NULL;

/* A software timer that is started from the tick hook. */
static TimerHandle_t xTimer = NULL;

/*-----------------------------------------------------------*/

static uint32_t mg_queue_send_cnt = 0;
static uint32_t mg_timer_event_received = 0;
static uint32_t mg_msg_event_received = 0;
static uint32_t mg_tick_cnt = 0;

#  define console_print printf

/*** SEE THE COMMENTS AT THE TOP OF THIS FILE ***/
void main_blinky(void)
{
  const TickType_t xTimerPeriod = mainTIMER_SEND_FREQUENCY_MS;

  /* Create the queue. */
  xQueue = xQueueCreate(mainQUEUE_LENGTH, sizeof(uint32_t));

  if (xQueue != NULL) {
    /* Start the two tasks as described in the comments at the top of this
     * file. */
    xTaskCreate(prvQueueReceiveTask,             /* The function that implements the task. */
                "Rx",                            /* The text name assigned to the task - for debug only as it is
                                                    not used by the kernel. */
                configMINIMAL_STACK_SIZE,        /* The size of the stack to allocate to the task. */
                NULL,                            /* The parameter passed to the task - not used in this simple
                                                    case. */
                mainQUEUE_RECEIVE_TASK_PRIORITY, /* The priority assigned to the task. */
                NULL);                           /* The task handle is not required, so NULL is passed. */

    xTaskCreate(prvQueueSendTask, "TX", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_SEND_TASK_PRIORITY, NULL);

    /* Create the software timer, but don't start it yet. */
    xTimer = xTimerCreate("Timer",                    /* The text name assigned to the software timer - for debug
                                                         only as it is not used by the kernel. */
                          xTimerPeriod,               /* The period of the software timer in ticks. */
                          pdTRUE,                     /* xAutoReload is set to pdTRUE. */
                          NULL,                       /* The timer's ID is not used. */
                          prvQueueSendTimerCallback); /* The function executed when the timer expires. */

    if (xTimer != NULL) {
      xTimerStart(xTimer, 0);
    }

    /* Start the tasks and timer running. */
    vTaskStartScheduler();
  }

  /* If all is well, the scheduler will now be running, and the following
   * line will never be reached.  If the following line does execute, then
   * there was insufficient FreeRTOS heap memory available for the idle and/or
   * timer tasks  to be created.  See the memory management section on the
   * FreeRTOS web site for more details. */
  for (;;) {}
}

/*-----------------------------------------------------------*/

static void prvQueueSendTask(void* pvParameters)
{
  TickType_t       xNextWakeTime;
  const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
  const uint32_t   ulValueToSend = mainVALUE_SENT_FROM_TASK;

  /* Prevent the compiler warning about the unused parameter. */
  (void)pvParameters;

  /* Initialise xNextWakeTime - this only needs to be done once. */
  xNextWakeTime = xTaskGetTickCount();

  for (;;) {
    mg_queue_send_cnt++;
    /* Place this task in the blocked state until it is time to run again.
     *  The block time is specified in ticks, pdMS_TO_TICKS() was used to
     *  convert a time specified in milliseconds into a time specified in ticks.
     *  While in the Blocked state this task will not consume any CPU time. */
    vTaskDelayUntil(&xNextWakeTime, xBlockTime);

    /* Send to the queue - causing the queue receive task to unblock and
     * write to the console.  0 is used as the block time so the send operation
     * will not block - it shouldn't need to block as the queue should always
     * have at least one space at this point in the code. */
    xQueueSend(xQueue, &ulValueToSend, 0U);
  }
}

/*-----------------------------------------------------------*/

static void prvQueueSendTimerCallback(TimerHandle_t xTimerHandle)
{
  const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TIMER;

  /* This is the software timer callback function.  The software timer has a
   * period of two seconds and is reset each time a key is pressed.  This
   * callback function will execute if the timer expires, which will only happen
   * if a key is not pressed for two seconds. */

  /* Avoid compiler warnings resulting from the unused parameter. */
  (void)xTimerHandle;

  /* Send to the queue - causing the queue receive task to unblock and
   * write out a message.  This function is called from the timer/daemon task, so
   * must not block.  Hence the block time is set to 0. */
  xQueueSend(xQueue, &ulValueToSend, 0U);
}

/*-----------------------------------------------------------*/

static void prvQueueReceiveTask(void* pvParameters)
{
  uint32_t ulReceivedValue;

  /* Prevent the compiler warning about the unused parameter. */
  (void)pvParameters;

  for (;;) {
    /* Wait until something arrives in the queue - this task will block
     * indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
     * FreeRTOSConfig.h.  It will not use any CPU time while it is in the
     * Blocked state. */
    xQueueReceive(xQueue, &ulReceivedValue, portMAX_DELAY);

    /* To get here something must have been received from the queue, but
     * is it an expected value?  Normally calling printf() from a task is not
     * a good idea.  Here there is lots of stack space and only one task is
     * using console IO so it is ok.  However, note the comments at the top of
     * this file about the risks of making Linux system calls (such as
     * console output) from a FreeRTOS task. */
    if (ulReceivedValue == mainVALUE_SENT_FROM_TASK) {
      console_print("Message received from task #%d\n", mg_msg_event_received);
      mg_msg_event_received++;
    } else if (ulReceivedValue == mainVALUE_SENT_FROM_TIMER) {
      console_print("Message received from software timer #%d\n", mg_timer_event_received);
      mg_timer_event_received++;
    } else {
      console_print("Unexpected message\n");
    }
  }
}

/*-----------------------------------------------------------*/

void run(void)
{
  console_print("Abort with CTRL+C\n");
  main_blinky();
}

#else

static void demo_task1(void* parameters)
{
  (void)parameters;

  vTaskDelay(500 / portTICK_PERIOD_MS);
  console_print("%s#%d\n", __func__, __LINE__);
  vTaskDelay(500 / portTICK_PERIOD_MS);
  console_print("%s#%d\n", __func__, __LINE__);
  while (1) {
    vTaskDelay(1);
  }
}

static void demo_task2(void* parameters)
{
  (void)parameters;

  vTaskDelay(200 / portTICK_PERIOD_MS);
  console_print("%s#%d\n", __func__, __LINE__);
  vTaskDelay(500 / portTICK_PERIOD_MS);
  console_print("%s#%d\n", __func__, __LINE__);
  while (1) {
    vTaskDelay(1);
  }
  //vTaskEndScheduler();
}

void run()
{
  xTaskCreate(demo_task1, "DemoTask1", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
  xTaskCreate(demo_task2, "DemoTask2", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2), NULL);
  vTaskStartScheduler();
}

#endif

void vApplicationTickHook()
{
  mg_tick_cnt++;
}

int main(int argc, char** argv)
{
  (void)argc;
  (void)argv;
  run();

  return 0;
}
