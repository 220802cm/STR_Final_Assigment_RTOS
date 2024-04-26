#include <stdio.h>
#include <stdio.h>

#include "task.h"    
#include "timers.h"
#include "semphr.h"
#include "FreeRTOS.h"
#include "console.h"
#include "ipsa_sched.h"

// Task function declarations
// Declaration of static functions ensures they are local to this file.
static void vTask1(void *pvParameters);
static void vTask2(void *pvParameters);
static void vTask3(void *pvParameters);
static void vTask4(void *pvParameters);
static void vTask5(void *pvParameters);

// Scheduler initialization functionQ

void ipsa_sched() {
    // Create tasks with varying priorities
    // Each task creation function call specifies the task function, task name, stack size, task input parameters, priority, and task handle.
    
    xTaskCreate(vTask1, "Task_welcome", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+0, NULL);
    xTaskCreate(vTask2, "Task_conversion", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(vTask3, "Task_multiplication", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(vTask4, "Task_search", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
    xTaskCreate(vTask5, "Task_bonus", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);

    // Start the scheduler, which is responsible for the management of tasks.

    vTaskStartScheduler();

static void task1(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(750); // Convert millisecond delay to ticks
    printf("Working\n");
    vTaskDelay(xDelay); // Delay task for specified ticks that characterize the period of the task.
}

static void task2(void *pvParameters)
{   
    const TickType_t xDelay = pdMS_TO_TICKS(750);
    double temp_fahrenheit = 70.0;
    double temp_celsius = (temp_fahrenheit - 32)*(5/9);
    printf("The temperature conversion is: %.2f F = %.2f C\n", temp_fahrenheit, temp_celsius);
    vTaskDelay(xDelay);
}

static void task3(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(750);
    long int numb1 = 6466865;
    long int numb2 = 5440044;
    long int mult = numb1 * numb2;
    printf("The multiplication betwen %d and %d is %ld\n ", numb1, numb2, mult);
    vTaskDelay(xDelay);

}

static void task4(void *pvParameters) {
        const TickType_t xDelay = pdMS_TO_TICKS(750);
    int arr[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
    int key = 21; // Element to search
    int moy, low = 0, end = 49;
    while (low <= end) {
        moy = (low + end) / 2;
        if (arr[moy] < key) {
            low = moy + 1;
        } else if (arr[moy] > key) {
            end = moy - 1;
        } else {
            printf("The element %d is found at index %d\n", key, moy);
            return;
        }
    }
    printf("The element %d was not found\n", key);
    vTaskDelay(xDelay);

}

static void task5(void *pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(750);
    printf("The task 5 is starting\n");
    sleep(100000); // Simulates 100 ms task duration
    printf("The task 5 is completed.\n");
    vTaskDelay(Delay);

}

}