# Guia Rápido: Configuração da Arduino IDE para ESP32

Este guia detalha os passos necessários para configurar a Arduino IDE para programar o módulo ESP32, permitindo a criação de projetos de IoT.

---

## Passo 1: Instalar a Arduino IDE

1. **Download da IDE**: Acesse [Arduino.cc](https://www.arduino.cc/en/software) e baixe a última versão.
2. **Instalação**: Siga as instruções específicas para o seu sistema operacional.

---

## Passo 2: Configurar a IDE para o ESP32

1. **Adicionar Gerenciador de Placas do ESP32**:
   - Acesse **Arquivo > Preferências**.
   - Em "URL Adicional para Gerenciadores de Placas", insira:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Salve clicando em **OK**.

2. **Instalar o Suporte ao ESP32**:
   - Vá em **Ferramentas > Placa > Gerenciador de Placas**.
   - Pesquise por **ESP32**.
   - Selecione "ESP32 by Espressif Systems" e clique em **Instalar**.

---

## Passo 3: Configurar Parâmetros da IDE

1. **Selecionar a Placa**:
   - Em **Ferramentas > Placa**, escolha o modelo **ESP32 Dev Module**.

2. **Definir Configurações Padrão**:
   - **Flash Size:** 4MB.
   - **CPU Frequency:** 240 MHz.
   - **Upload Speed:** 115200.

3. **Selecionar a Porta**:
   - Conecte o ESP32 via USB e selecione a porta correspondente em **Ferramentas > Porta**.

---

## Passo 4: Testar o Ambiente

1. Abra o exemplo **WiFiScan** em **Arquivo > Exemplos > WiFi**.
2. Compile e carregue o código clicando em **Carregar**.
3. Acesse o Monitor Serial e veja a lista de redes WiFi detectadas.

---

## Solução de Problemas

- **Porta Não Detectada:** Instale o driver CP2102/CH340 correspondente ao chip do ESP32.
- **Erro no Upload:** Mantenha o botão **BOOT** pressionado durante o upload.
- **Configurações Incorretas:** Verifique os logs da IDE para ajustar parâmetros.

---

Com esses passos, você estará pronto para explorar o ESP32!
