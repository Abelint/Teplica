// Подключаем библиотеку для работы с HTTP-протоколом
#include <HTTPClient.h>

// Вводим имя и пароль точки доступа
const char* ssid = "TERRA";
const char* password = "ae2w4b9w";

void setup() {
  Serial.begin(9600);
  // делаем небольшую задержку на открытие монитора порта
  delay(5000);
  // подключаемся к Wi-Fi сети
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Соединяемся с Wi-Fi..");
  }
  Serial.println("Соединение с Wi-Fi установлено");
}

void loop() {
 post_zapros();
}

void post_zapros(){
   HTTPClient http;    //Объявить объект класса HttpClient

  http.begin("http://f0784818.xsph.ru/api.php");      //Укажите адрес запроса
  http.addHeader("Content-Type", "application/form-data");//"text/plain");  //Укажите заголовок типа содержимого
  String httpRequestData = "id_divas";//"id_divas=tPmAT5Ab3j7F9&sensor=BME280&value1=24.25&value2=49.54&value3=1005.14";

  // Формирование POST-запроса
  String postData = "id_divas=123"; // Параметры для отправки
  String request = "POST /path/to/endpoint HTTP/1.1\r\n";
         request += "Host: " + String("http://f0784818.xsph.ru/api.php") + "\r\n";
                   request +="Content-Type: application/x-www-form-urlencoded\r\n";
                   request +="Content-Length: " + String(postData.length()) + "\r\n\r\n";
 request +=                  postData;

  

  int httpCode = http.POST(postData);   //Отправьте запрос
  
  String payload = http.getString();                  //Получите полезную нагрузку ответа

  Serial.println(httpCode);   //Распечатать код возврата HTTP
  Serial.println(payload);    //Полезная нагрузка для ответа на запрос печати

  http.end();  //Закрыть соединение


  delay(10000);  //Ждем 10 сек.
}


void get_zapros(){
   // выполняем проверку подключения к беспроводной сети
  if ((WiFi.status() == WL_CONNECTED)) {
    // создаем объект для работы с HTTP
    HTTPClient http;
    // подключаемся к веб-странице
    http.begin("http://f0784818.xsph.ru/api.php");
    // делаем GET запрос
    int httpCode = http.GET();
    // проверяем успешность запроса
    if (httpCode > 0) {
      // выводим ответ сервера
      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }
    else {
      Serial.println("Ошибка HTTP-запроса");
    }
    // освобождаем ресурсы микроконтроллера
    http.end();
  }
  delay(10000);
}