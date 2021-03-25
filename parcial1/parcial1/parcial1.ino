//----------------------------------------------------------
// Print to Serial monitor using 2 tasks
// Accurately dalay
// Delete, Suspend and resume functions
//----------------------------------------------------------

#include <Arduino_FreeRTOS.h>
#define led 13

void Task_Print1(void *param);
/*void Task_Print2(void *param);*/
void Task_Print3(void *param);

TaskHandle_t Task_Handle1;
/*TaskHandle_t Task_Handle2;*/
TaskHandle_t Task_Handle3;

int counter = 0;
int sw=0;
/*int contador=0;*/
int segundos=0;
int valor = analogRead(A0);

void setup() {
  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
 
  xTaskCreate(Task_Print1, "Tasks1", 100, NULL, 3, &Task_Handle1);
  /*xTaskCreate(Task_Print2, "Tasks2", 100, NULL, 2, &Task_Handle2);*/
  xTaskCreate(Task_Print3, "Tasks3", 100, NULL, 1, &Task_Handle3);
}

void loop() {
  // 
}

void Task_Print1(void *param){
  (void) param;

  while(1){
    
    
    segundos=segundos+1;
    Serial.println(segundos);
 
    }
    
     vTaskDelay(1000/portTICK_PERIOD_MS); 
  }

/*void Task_Print2(void *param){
  (void) param;

  
  while(1){
   
    contador=contador+1;


    if(contador==3){
      Serial.println(valor);
    contador=0; 
    }
    if(counter==10){
      vTaskSuspend(Task_Handle2);
    }
    
     vTaskDelay(1000/portTICK_PERIOD_MS); // The Arduino will print to serial monitor each 1sec
  }
}*/

void Task_Print3(void *param){
  (void) param;
  TickType_t getTick;
  getTick = xTaskGetTickCount();
  counter ++;
  // Infinite loop
  while(1){
 
    sw= sw+1;
    if(sw == 2){
      digitalWrite(led, HIGH);
      sw=0;
    }
    if(counter==30){
         vTaskDelete(Task_Handle3); // Then you cannot call and re run the task again
    }

     /*if(counter==20){
      vTaskResume(Task_Handle2);
      
          } */
    }
    /*xTaskDelayUntil(&getTick, 1000 / portTICK_PERIOD_MS);*/
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
