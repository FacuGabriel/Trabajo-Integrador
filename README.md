# Trabajo-Integrador
Trabajo Integrador: Sistema de Riego Automático
Información del Proyecto


Alumno: Facundo Gabriel Araujo 

Profesor/es: Ing. Gustavo Viard / Ing. Damián Corbalán 


Curso: 2°12 

Modelo de sistema a realizar:
Sistema de Riego Automático, en base a humedad en la tierra.
El proyecto que decidí realizar es un sistema de riego automático que trabaja en sitios o zonas donde el agua dulce existe en bajas proporciones, actúa cuando recibe bajas medidas de humedad en la tierra donde se halla o vaya a haber una planta/árbol/vegetal. Inspirado en el sistema de goteo que ocupan en Israel debido a la baja cantidad de agua dulce que hay en dicho país.
El esquema que plantearía para realizar dicho proyecto es, un circuito cerrado donde existen estados, que cumplan cierto ciclo, el planteado seria:

1° Primer estado, Reposo/Espera, el sistema ocupa un espacio de tiempo para que no este midiendo y ejecutando todo el rato.

2° Segundo estado, Medición, El sistema opera bajo un receptor de humedad el cual detectara y se le crearan condiciones en las que dependiendo un nivel de humedad se activara el riego, caso contrario volverá al estado de Reposo.

3° Tercer estado, Riego, El sistema al detectar un nivel de humedad bajo activara algún mecanismo físico para que durante cierto tiempo riegue la tierra. Una vez finalizado volverá al estado de reposo.

4° Cuarto estado, Mensaje Alarma, el sistema activara una alarma (led rojo) cuando luego del riego la humedad de la tierra se mantenga igual, en resumidas es cuando no halla agua en el regador, luego de este estado se devolverá al estado de espera.

<img width="755" height="455" alt="image" src="https://github.com/FacuGabriel/Trabajo-Integrador/blob/main/Imagenes/Maquina%20de%20estado.png" />


A medida que me puse a realizar el proyecto tuve que "correjir" o aclarar ciertas cosas:

Primero, el sensor de humedad, el funcionamiento en grandes palabras del sensor de humedad es generar una corriente electrica que mida la conductividad que hay en el suelo, si es alta significa que hay humedad, si es baja significa que el suelo esta seco. Por eso y que los sensores que vi son de arduino, para facilitar la lectura y problemas decidi utilizar en su remplazo un potenciometro que basicamente puede utilizarse de la misma manera midiendo el voltaje. De ahi hago una estimacion y realize las comparaciones.

Segundo, el sistema de riego, el sistema de riego se puede hacer de varias maneras, una bomba, una valvula, un mecanismo mecanico simple, etc. Por eso y para facilitarme la tarea un poco simplemente puse un led verde que me indique cuando esta trabajando el sistema de riego.

Tercero y ultimo, los tiempos de espera, para que no este en constante uso el sensor de humedad coloque un tiempo de espera suficiente para que de tiempo a tanto humedeserce el suelo como para el descanso del sensor. Estos tiempos son en conveniencia para todos los estados, tiempo de espera es de unos 5 ~ min, el del sensor de unos 10 ~ seg, y el de riego de unos 30 ~ seg.

Esquematico:
---

<img width="755" height="455" alt="image" src="https://github.com/FacuGabriel/Trabajo-Integrador/blob/main/Imagenes/Esquematico.png" />


---

Video: 

https://youtu.be/-fW3sTUmmqc

Aclaraciones, acorte el tiempo de espera por practicidad en el video, el humbral de humedad es que si es menor a 20% riega.
