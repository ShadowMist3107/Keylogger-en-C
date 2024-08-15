Keylogger en C para Linux

## Hecho por: Mario Iván Díaz Robledo

Este es un programa simple escrito en C que detecta y registra las teclas presionadas en un sistema Linux. El programa captura tanto teclas comunes como teclas especiales, y guarda las entradas en un archivo de texto.

## Instrucciones de Uso

### 1. Preparación

1. **Identificar el dispositivo de entrada**:
   - Abre la terminal y usa `evtest` para identificar cuál es el dispositivo de entrada correspondiente a tu teclado.
   - Instala `evtest` (si no lo tienes instalado) con el siguiente comando:
     ```bash
     sudo apt install evtest
     ```
   - Ejecuta `evtest` y selecciona el dispositivo de entrada del teclado.

2. **Modifica el código**:
   - Abre `keylogger.c` en un editor de texto y reemplaza `"/dev/input/event0"` en `#define INPUT_DEVICE` con la ruta correcta para tu dispositivo de entrada.

### 2. Compilar el Programa

En la terminal, navega hasta el directorio donde tienes el archivo `keylogger.c` y compílalo con el siguiente comando:

```bash
gcc keylogger.c -o keylogger
```

### 3. Ejecutar el Programa

Para ejecutar el keylogger, utiliza:

```bash
sudo ./keylogger
```

> **Nota**: Debes ejecutar el programa con permisos de superusuario (`sudo`) porque requiere acceso directo al dispositivo de entrada.

### 4. Verificar la Salida

El programa guardará las teclas registradas en un archivo llamado `keylog.txt` en el mismo directorio donde se ejecuta el programa. Puedes verificar el contenido del archivo usando:

```bash
cat keylog.txt
```

### 5. Detener el Programa

Para detener el programa, usa `Ctrl + C` en la terminal donde está ejecutándose.

## Supuestos del Programa

- **Dispositivo de Entrada Correcto**: Se asume que el usuario ha identificado correctamente el dispositivo de entrada correspondiente al teclado y ha modificado el código en consecuencia.
- **Permisos de Root**: El programa debe ejecutarse con permisos de root para acceder al dispositivo de entrada.
- **Entorno Linux**: El programa está diseñado para ejecutarse en un entorno Linux y no es compatible con otros sistemas operativos.

## Casos de Uso

1. **Monitoreo de Actividad del Teclado**: El programa puede ser utilizado para registrar la actividad del teclado en tiempo real, lo cual puede ser útil para pruebas o auditorías en sistemas controlados.
   
2. **Análisis de Entradas de Teclado**: Desarrolladores pueden utilizar este keylogger para analizar cómo se interactúa con el teclado en diversas aplicaciones, obteniendo insights sobre la frecuencia y patrón de uso de teclas.
   
3. **Auditoría de Seguridad**: En un entorno controlado y con autorización explícita, este keylogger podría ser usado para auditar y monitorear la entrada de datos sensibles.

> **Advertencia**: Este software debe ser utilizado de manera ética y legal. No utilices este keylogger sin el consentimiento explícito del usuario del sistema en el que se implementa.

---

Este README proporciona las instrucciones básicas y los supuestos necesarios para utilizar el programa de manera efectiva y segura.


Este `README.md` proporciona una guía clara para instalar, configurar, y usar el keylogger, junto con los supuestos del programa y algunos casos de uso aplicables. Asegúrate de adaptarlo a tus necesidades específicas si hay alguna particularidad en tu implementación.
