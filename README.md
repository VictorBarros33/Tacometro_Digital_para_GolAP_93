
# 📘 **README – Tacômetro Digital para Gol 93 (Motor AP)**

### 🛠 Projeto de Leitura de RPM usando Arduino + Optoacoplador + Display OLED

### Autor: **Víctor Aurélio da Silva Barros**

---

# 🚗 **📌 Sobre o Projeto**

Este repositório contém o desenvolvimento completo de um **Tacômetro Digital** para o **Gol 93 Motor AP**, utilizando:

* Sinal da bobina (Terminal 1 – negativo)
* Isolamento por optoacoplador **PC817**
* Conversão de pulsos → RPM
* Código orientado a objetos (C++ OOP)
* Exibição em um **Display OLED SSD1306 I2C**

O objetivo é criar um sistema confiável, seguro e expansível, permitindo leituras reais de RPM mesmo em veículos **sem OBD2**, como o Gol AP 93.

---

# 🧩 **Arquitetura do Sistema**

O projeto foi organizado em **programação orientada a objetos (OOP)** para facilitar manutenção e upgrades.

### ✔ Classes implementadas

| Classe        | Função                                          |
| ------------- | ----------------------------------------------- |
| `RPMReader`   | Lê pulsos vindos do optoacoplador (interrupção) |
| `Tachometer`  | Converte pulso/segundo → RPM                    |
| `DisplayOLED` | Exibe o valor de RPM em um OLED 128x64          |
| `main.ino`    | Fluxo principal do sistema                      |

---

# ⚙️ **Fluxo de Funcionamento**

```text
Bobina (Terminal 1) 
    ↓ (pulso ~100V)
Resistor de 10k–20k (1–2W)
    ↓
Optoacoplador PC817 (isolamento)
    ↓ (pulso seguro 0–5V)
Interrupção no Arduino (D2)
    ↓
Classe RPMReader
    ↓
Classe Tachometer
    ↓
Classe DisplayOLED
    ↓
Valor de RPM no painel
```

---

# 🧱 **Hardware Necessário**

### 📝 Lista de peças

* Arduino Nano / Uno
* Display OLED SSD1306 (I2C – 128x64)
* Optoacoplador PC817
* Resistor 10k–20k 1–2W (lado da bobina)
* Resistor 10k pull-up (lado do Arduino)
* Conversor buck 12V→5V
* Fios e protoboard

---

# 🔌 **Diagrama Elétrico (ASCII – ideal para GitHub)**

```
                 ┌─────────────────────────┐
                 │      Bobina AP 93       │
                 │  Terminal 1 (Negativo)  │
                 └───────────┬─────────────┘
                             │
                      [R1 – 10k/20k]
                             │
                             ▼
                    ┌────────────────┐
                    │   PC817        │
                    │ (Optoacoplador)│
Terra do Carro  --->│ Pin2      Pin1 │<--- R1
                    │                │
Arduino GND     --->│ Pin3      Pin4 │----> Pulso isolado (D2)
                    └────────────────┘
                             │
                        [R2 – 10k Pull-up]
                             │
                             ▼
                       Arduino D2
```

---

# 💻 **Código Orientado a Objetos (Descrição)**

### 🔹 **1. `RPMReader`**

Responsável por contar pulsos via interrupção:

* Incrementa `pulseCount` a cada pulso
* Funções:

  * `begin()`
  * `handlePulse()`
  * `getPulses()`
  * `reset()`

---

### 🔹 **2. `Tachometer`**

Converte pulsos → RPM usando:

```
RPM = (pulsos / 2) * 60
```

(Motor AP gera 2 pulsos por volta do virabrequim)

---

### 🔹 **3. `DisplayOLED`**

Exibe RPM em:

* Fonte grande
* Layout limpo
* Atualização a cada segundo

---

# 🧠 **Tecnologias Utilizadas**

* Arduino C++ (OOP)
* Interrupções (attachInterrupt)
* Eletrônica automotiva (isolamento por optoacoplador)
* Biblioteca Adafruit SSD1306
* Display OLED I2C

---

# ▶️ **Como Usar**

1. Monte o circuito de isolamento da bobina → optoacoplador
2. Carregue o código no Arduino
3. Ligue o display OLED
4. Dê partida no carro e veja o RPM em tempo real

---

# 🔮 **Melhorias Futuras (ideias já planejadas)**

* Filtro digital (média móvel) para suavizar RPM
* Gráfico de RPM no OLED
* Gauge semicircular estilo painel esportivo
* App Android recebendo RPM via Bluetooth
* Versão CANBus para carros mais novos

---

# 📂 **Estrutura sugerida do repositório**

```
📁 tacometro-gol-ap
│
├── src/
│   ├── RPMReader.h
│   ├── RPMReader.cpp
│   ├── Tachometer.h
│   ├── Tachometer.cpp
│   ├── DisplayOLED.h
│   ├── DisplayOLED.cpp
│   └── main.ino
│
├── diagrams/
│   └── esquema_ascii.txt
│
├── docs/
│   ├── explicacao_tecnica.pdf
│   └── fotos_instalacao/
│
└── README.md
```

---

# 🏁 **Conclusão**

Este projeto demonstra como integrar **eletrônica automotiva + Arduino + C++ orientado a objetos** para criar um tacômetro moderno e confiável para veículos antigos como o Gol 93.

Sinta-se à vontade para clonar, modificar e evoluir este projeto!
