int PIN_P = A0;
int PIN_B = 9;
int ValorePrecedente = -1;
int potenziometro;
int potenziometro_m;
int Duty_cycle;

int A_1 = 2;
int B_1 = 3;
int C_1 = 4;
int D_1 = 5;

int A_2 = 6;
int B_2 = 7;
int C_2 = 8;
int D_2 = 10;

int decine;
int unita;

float Tensione;

void setup() {
    pinMode(PIN_P, INPUT);
    pinMode(PIN_B, OUTPUT);

    pinMode(A_1, OUTPUT);
    pinMode(B_1, OUTPUT);
    pinMode(C_1, OUTPUT);
    pinMode(D_1, OUTPUT);
    pinMode(A_2, OUTPUT);
    pinMode(B_2, OUTPUT);
    pinMode(C_2, OUTPUT);
    pinMode(D_2, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Lettura del valorer del potenziometro
    potenziometro = analogRead(PIN_P);
    potenziometro_m = map(potenziometro, 0, 1023, 0, 255);
    analogWrite(PIN_B, potenziometro_m);

    // Calcolo della tensione:
    Tensione = potenziometro / 1023.0 * 5.0;

    // Calcolo del Duty_cycle:
    Duty_cycle = (Tensione / 5) * 100;

    // Stampa dei valori solo se variano:
    if (potenziometro < ValorePrecedente - 10 ||
        potenziometro > ValorePrecedente + 10) {
        Serial.print("Valore di resistenza del Potenziometro:     ");
        Serial.println(potenziometro);
        Serial.print("Valore della Tensione:                      ");
        Serial.println(Tensione);
        Serial.print("Duty Cycle:                                 ");
        Serial.println(Duty_cycle);

        ValorePrecedente = potenziometro;
    }

    decine = Duty_cycle / 10;
    unita = Duty_cycle % 10;
    switch (decine) {
        case 0:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, LOW);
            digitalWrite(D_2, LOW);
            break;
        case 1:
            digitalWrite(A_1, LOW);
            digitalWrite(B_1, HIGH);
            digitalWrite(C_1, LOW);
            digitalWrite(D_1, LOW);
            break;
        case 2:
            digitalWrite(A_1, HIGH);
            digitalWrite(B_1, HIGH);
            digitalWrite(C_1, LOW);
            digitalWrite(D_1, LOW);
            break;
        case 3:
            digitalWrite(A_1, LOW);
            digitalWrite(B_1, HIGH);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, LOW);
            break;
        case 4:
            digitalWrite(A_1, HIGH);
            digitalWrite(B_1, LOW);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, LOW);
            break;
        case 5:
            digitalWrite(A_1, LOW);
            digitalWrite(B_1, LOW);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, LOW);
            break;
        case 6:
            digitalWrite(A_1, HIGH);
            digitalWrite(B_1, LOW);
            digitalWrite(C_1, LOW);
            digitalWrite(D_1, HIGH);
            break;
        case 7:
            digitalWrite(A_1, LOW);
            digitalWrite(B_1, HIGH);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, HIGH);
            break;
        case 8:
            digitalWrite(A_1, HIGH);
            digitalWrite(B_1, HIGH);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, HIGH);
            break;
        case 9:
            digitalWrite(A_1, LOW);
            digitalWrite(B_1, LOW);
            digitalWrite(C_1, HIGH);
            digitalWrite(D_1, HIGH);
            break;
    }

    switch (unita) {
        case 0:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, LOW);
            digitalWrite(D_2, LOW);
            break;
        case 1:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, HIGH);
            digitalWrite(C_2, LOW);
            digitalWrite(D_2, LOW);
            break;
        case 2:
            digitalWrite(A_2, HIGH);
            digitalWrite(B_2, HIGH);
            digitalWrite(C_2, LOW);
            digitalWrite(D_2, LOW);
            break;
        case 3:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, HIGH);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, LOW);
            break;
        case 4:
            digitalWrite(A_2, HIGH);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, LOW);
            break;
        case 5:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, LOW);
            break;
        case 6:
            digitalWrite(A_2, HIGH);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, LOW);
            digitalWrite(D_2, HIGH);
            break;
        case 7:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, HIGH);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, HIGH);
            break;
        case 8:
            digitalWrite(A_2, HIGH);
            digitalWrite(B_2, HIGH);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, HIGH);
            break;
        case 9:
            digitalWrite(A_2, LOW);
            digitalWrite(B_2, LOW);
            digitalWrite(C_2, HIGH);
            digitalWrite(D_2, HIGH);
            break;
    }
}