# Monitoramento de Tensão com ESP32 utilizando ADC

Este projeto utiliza um ESP32 para monitorar tensões analógicas e enviar notificações via WhatsApp usando a API CallMeBot. Este README detalha o funcionamento do ADC no ESP32 e como ele é usado neste projeto.

---

## O que é o ADC?

ADC (Conversor Analógico para Digital) é um componente que converte um sinal analógico, como voltagem, em valores digitais que podem ser processados pelo ESP.
---

## Diferenças entre o ADC do ESP32 e ESP8266

### ESP32
- **Resolução:** 12 bits (0 a 4095).
- **Canais ADC:** Possui dois ADCs (ADC1 e ADC2), com até 18 canais disponíveis.
- **Intervalo de Tensão:** 0V a 3.3V por padrão (configurável).
- **Características Adicionais:** Possibilidade de atenuação para ajustar a faixa de medição até 3.9V, dependendo da configuração.

### ESP8266 Puro
- **Resolução:** 10 bits (0 a 1023).
- **Canais ADC:** Apenas um canal ADC disponível (GPIO A0).
- **Intervalo de Tensão:** 0V a 1.0V por padrão (é necessário um divisor de tensão para sinais superiores).

### ESP8266 NODEMCU
- **Resolução:** 10 bits (0 a 1023).
- **Canais ADC:** Apenas um canal ADC disponível (GPIO A0).
- **Intervalo de Tensão:** 0V a 3.3V por padrão.

---

## Configuração do ADC no Projeto

### Pino de Entrada Analógica
Neste projeto, utilizamos o pino GPIO 34, que é um canal do ADC1. Este pino é utilizado para medir a voltagem analógica aplicada ao ESP32.

### Conversão de Valores
A leitura do ADC fornece um valor digital proporcional à tensão aplicada. No ESP32, a relação entre a leitura e a tensão é calculada como:

```c++
float voltageValue = (voltage / 4095.0) * 3.3;
```

- **voltage:** Leitura digital do ADC (0 a 4095).
- **3.3:** Voltagem máxima de referência.

Se você estiver usando uma voltagem de referência diferente, substitua o valor `3.3` no código pela sua voltagem de referência.

---

## Envio de Notificações

### Integração com o CallMeBot
Este projeto utiliza a API CallMeBot para enviar notificações via WhatsApp. Sempre que a tensão lida exceder 2V, o ESP32 envia uma mensagem com o valor da tensão.

### Fluxo do Projeto
1. O ESP32/ESP8266 mede a tensão analógica usando o ADC.
2. Converte o valor lido em uma tensão real.
3. Se a voltagem for maior que 2V, envia uma notificação via CallMeBot.

### Requisitos
- Rede Wi-Fi configurada.
- Uma chave de API válida da CallMeBot.

---

## Links Úteis

- [Artigo detalhado sobre ADC no ESP32/ESP8266](https://microcontrollerslab.com/esp32-esp8266-adc-micropython-measure-analog-readings/)
- [CallMeBot WhatsApp API](https://www.callmebot.com/)

---

Com este projeto, você pode facilmente monitorar sinais analógicos e receber alertas em tempo real, explorando as capacidades do ESP32 no mundo IoT.
