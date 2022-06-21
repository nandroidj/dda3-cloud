# DAIoT 2022

## Conexión del ESP32 a Google Cloud IoT-Core

Configurar SSID y PASSWORD de la red Wi-Fi en el archivo smart_config.c

Configurar tu ID de dispositivo segun tu nombre, en el archivo mqtt_basico.h

El certificado incluido en el archivo pemhey.h fue generado en la consola de Google Cloud.
Se utilizo el siguiente comando:

openssl req -x509 -nodes -newkey rsa:2048 -keyout rsa_lz_private.pem -out rsa_lz_cert.pem -subj "/CN=unused" -days 36500 


Descargar de GCP el certificado CA mínimo y convertirlo a formato PEM con OPENSSL:
 * https://cloud.google.com/iot/docs/how-tos/mqtt-bridge#using_a_long-term_mqtt_domain
 * Cert primario: https://pki.goog/gtsltsr/gtsltsr.crt
 * Cert backup: https://pki.goog/gsr4/GSR4.crt
 
openssl x509 -inform DER -in gtsltsr.crt -out primary.pem -text
Copiar el fragmento desde BEGIN a END dentro del archivo "gcp_min_ca.h"


# DDA3 Project

## The Clouding way

Se utilizaran los servicios:

* *Capa de conectividaad y procesamiento*

- IoT Core

- Pub/Sub

- Cloud Functions


* *Capa de almacenamiento*

- BigQuery


* *Capa de visualizacion*

- Data Studio


**Ver diapo 4 de clase 6 - DAIoT**




## Etapa 1 - ESP32 Core

En la **diapo 5** [*21:31*] se muestra el **paso a paso** con las consideraciones a tener en cuenta al momento de flashear el *ESP32* con los archivos del repo `DAIoT_2022_GCP_Mutual_auth_ESP32`. 



## Etapa 2 - Google Cloud Platform

1. Se realiza el *sign up* en *Google Cloud Platform*

2. En el top bar al lado del logo de la plataforma se encuentra un boton que permite clickear sobre el actual proyecto. Presionar el boton y seleccionar la opcion `PROYECTO NUEVO`.

3. Se le asigna el nombre `daiot-cloud` con la organizacion `fi.uba.ar` y la ubicacion `fi.uba.ar`; de alli se obtienen los siguientes datos:

```
Nombre del proyecto     daiot-cloud
Numero del proyecto     179023659029
ID de proyecto          daiot-cloud
```

Tener en cuenta que con el ID de proyecto propuesto, debe modicarse la linea 23 `#define IOTCORE_PROJECTID daiot-cloud` 


4. Ahora se procede a habilitar los servicios [*52:30*]. Se busca el servicio `IoT Core` y se presiona el boton `HABILITAR` (*ver punto 1 del paso a paso en slide 5 Habilitar GCP IoT Core*). 

5. En el margen superior dentro del scope del servicio se seleciona el boton `CREAR REGISTRO` (*ver punto 3 slide 5 Crear un registro que agrupe dispositivos en IoT Core*)

Se propone mantener las que se encuentran en las lineas 41 y 42:

```
#define IOTCORE_REGION			"us-central1"
#define IOTCORE_REGISTRY		"daiot_reg"
```

Luego, se deben registrar los temas de `Pub/Sub`. En caso de no registrarse nada, se publican y suscriben eventos del tema `events`.

Para crear un tema se presiona el dropdown de seleccion de temas y se apreta el boton en la zona inferior izquierda `CREAR TEMA`. Ali se propone el nombre `esp32-dht22` resultando como topic `projects/daiot-cloud/topics/esp32-dht22`

De esta manera, el tema por defeto pasa a ser `esp32-dht22`. Estos temas pueden ser utilizados como `triggers` en las cloud Functions

**Para esta implementacion no se configuran OPCIONES AVANZADAS**. Se deja todo como esta por defecto

Finalmmente, se presiona `CREAR` para forjar el registro

/var/folders/vs/03l94j_d2ng7gc_1t7m85nvr0000gp/T/TemporaryItems/NSIRD_screencaptureui_EJFDhs/Screen\ Shot\ 2022-06-21\ at\ 01.44.39.png 

En la imagen es posible ver que en la primera opcion del sidebar se tienen `Detalles del registro` creado


6. Luego, se proponen crear los certificados tal que sea posible asociar dispositivos a la plataforma (*ver punto 2 del slide 5*) [*1:00:00*]. 

El dispositivo arma un `jwt` con las claves provistas.

7. Abrir el `Cloud Shell` que se encuentra en el margen superior derecho del topbar principal. 

Posteriormente, ir al `README` del repo provisto para esta clase y tomar la linea con el comando y sus argumentos que permite la creacion de claves: `openssl req -x509 -nodes -newkey rsa:2048 -keyout rsa_fji_private.pem -out rsa_fji_cert.pem -subj "/CN=unused" -days 36500`

Desde el `Cloud Shell` se selecciona el icono con tres puntos en verticual dispuesto proximo al avatar del usuario y se selecciona `Descargar` para proceder a almacear los certificados creados en el disco local.

* Con el certificado `rsa_fji_cert` es con el que se **crean** los dispositivos. Este archivo (`rsa_fji_cert.pem`) va dentro del servicio `IoT Core`.

* El archivo `rsa_fji_private.pem` se debe agregar en el archivo `main/pem_key.h` en el arreglo de caracteres llamado `GCP_PEM_KEY`.

Finalmente, se cierra el `Cloud Shell` ya que no se usara mas.

**Aclaracion**: idealmente se deberian ccrear un par de claves `rsa_fji_private` y `rsa_fji_cert` por ccada dispositivo a conectar con el mismo flow propuesto.

**Aclaracion 2**: los certificados creados son aquellos para que google autentique a nuestro dispositivo. Para que la autenticacion sea mutua, se debe generar un CA self-signed donde el dispositivo autentique a Google.

En los comentarios del archivo `main/gcp_min_ca.h` se encuentra el paso a paso con los certificados a crear para que el dispositivo reconozca a Google.





8. Acto seguido, se va a la segunda opcion del sidebar llamada `Dispositivos` y se selecciona el boton `CREAR DISPOSITIVO`

* El nombre propuesto en `main/mqtt_basico.h` es `#define IOTCORE_DEVICEID  "device-"IOTCORE_DEVICE_NUMBER` siendo `IOTCORE_DEVICE_NUMBER`, `#define IOTCORE_DEVICE_NUMBER	"1xx" `

* En los Atributos no se propone agregar niguno. Es opcional

* Comunicacion, Cloud Logging y Auth, en Comunicacion y Cloud Logging se deja todo como esta. Luego, en `Autenticacion` se `agrega manualmente` el contenido del archivo `resa_fji_cert.pem` bajo el formato de clave publica `RS256_X509`.

* En `1:19:00` comenta como actualizar la configuracion de un dispositivo. En ccada reconexion del dispositivo al broker mqtt aparecera por el flujo de salida la nueva configuracion propuesta.

* En `1:21:10` comenta como eviar comandos


## Back to Etapa 1 - ESP32 Core

2. En `1:23:30` explica como resulto la config de la capa TLS desde el SDK (para visual studio, en la CLI haccer `idf menuconfig` o su semejante). habla del uso y no uso de CAs ccuando se tiene a GCloud asociado.

* En `gcp_min_ca.h` se encuentra un certificado CA de Google. De esta manera, el dispositivo esta validando que esta accediendo a Google



                                                **VISTO HASTA LOS 1:26:39**



```
I (889) wifi:connected with Lunihouse2.4, aid = 2, channel 6, BW20, bssid = 10:d7:b0:f7:00:44
I (889) wifi:security: WPA2-PSK, phy: bgn, rssi: -42
I (899) wifi:pm start, type: 1
```

## Etapa 3 - BigQuery

A partir de `2:29:00` arranca la parte del servicio con 

1. Se procede a buscar el servicio `BigQuery`

2. Se crea el dataset dentro del entorno `daiot_cloud` pertenciente a `daiot-cloud` (notar el guion medio y el guion bajo). 

3. Se crean las tablas y vistas propuestas en las diapos 10 a 15.


## Etapa 4 - Cloud Functions & Pub/Sub

A partir de `12:00` de la **Clase 6** arranca con estos servicios.

































