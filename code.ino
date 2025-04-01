int PIN_P = A0;
int ValoreB = 9;
int ValorePrecedente = -1;
int potenziometro;
int potenziometro_m;
int Duty_cycle;

int A1 = 2;
int B1 = 3;
int C1 = 4;
int D1 = 5;

int A2 = 6;
int B2 = 7;
int C2 = 8;
int D2 = 10;

int decine;
int unità;

float Tensione;

void setup() {
    pinMode(PIN_P, INPUT);
    pinMode(ValoreB, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Lettura del valorer del potenziometro
    potenziometro = analogRead(PIN_P);
    potenziometro_m = map(potenziometro, 0, 1023, 0, 255);
    analogWrite(ValoreB, potenziometro_m);

    // Calcolo della tensione:
    Tensione = potenziometro / 1023.0 * 5.0;

    // Calcolo del Duty_cycle:
    Duty_cycle = (Tensione / 5) * 100;

    // Stampa dei valori solo se variano:
    if (potenziometro != ValorePrecedente) {
        Serial.print("Valore di resistenza del Potenziometro:     ");
        Serial.println(potenziometro);
        Serial.print("Valore della Tensione:                      ");
        Serial.println(Tensione);
        Serial.print("Duty Cycle:                                 ");
        Serial.println(Duty_cycle);

        ValorePrecedente = potenziometro;
    }

    decine = Duty_cycle / 10;
    unità = Duty_cycle % 10;

    switch (decine) {
        case 1:
            digitalWrite(A1, LOW);   // A = 0
            digitalWrite(B1, HIGH);  // B = 1
            digitalWrite(C1, LOW);   // C = 0
            digitalWrite(D1, LOW);   // D = 0
            break;

        case 2:
            digitalWrite(A1, HIGH);  // A = 1
            digitalWrite(B1, HIGH);  // B = 1
            digitalWrite(C1, LOW);   // C = 0
            digitalWrite(D1, LOW);   // D = 0
            break;

        case 3:
            digitalWrite(A1, LOW);   // A = 0
            digitalWrite(B1, HIGH);  // B = 1
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, LOW);   // D = 0
            break;

        case 4:
            digitalWrite(A1, HIGH);  // A = 1
            digitalWrite(B1, LOW);   // B = 0
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, LOW);   // D = 0
            break;

        case 5:
            digitalWrite(A1, LOW);   // A = 0
            digitalWrite(B1, LOW);   // B = 0
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, LOW);   // D = 0
            break;

        case 6:
            digitalWrite(A1, HIGH);  // A = 1
            digitalWrite(B1, LOW);   // B = 0
            digitalWrite(C1, LOW);   // C = 0
            digitalWrite(D1, HIGH);  // D = 1
            break;

        case 7:
            digitalWrite(A1, LOW);   // A = 0
            digitalWrite(B1, HIGH);  // B = 1
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, HIGH);  // D = 1
            break;

        case 8:
            digitalWrite(A1, HIGH);  // A = 1
            digitalWrite(B1, HIGH);  // B = 1
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, HIGH);  // D = 1
            break;

        case 9:
            digitalWrite(A1, LOW);   // A = 0
            digitalWrite(B1, LOW);   // B = 0
            digitalWrite(C1, HIGH);  // C = 1
            digitalWrite(D1, HIGH);  // D = 1
            break;
    }

    switch (unità) {
        case 1:
            digitalWrite(A2, LOW);   // A = 0
            digitalWrite(B2, HIGH);  // B = 1
            digitalWrite(C2, LOW);   // C = 0
            digitalWrite(D2, LOW);   // D = 0
            break;

        case 2:
            digitalWrite(A2, HIGH);  // A = 1
            digitalWrite(B2, HIGH);  // B = 1
            digitalWrite(C2, LOW);   // C = 0
            digitalWrite(D2, LOW);   // D = 0
            break;

        case 3:
            digitalWrite(A2, LOW);   // A = 0
            digitalWrite(B2, HIGH);  // B = 1
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, LOW);   // D = 0
            break;

        case 4:
            digitalWrite(A2, HIGH);  // A = 1
            digitalWrite(B2, LOW);   // B = 0
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, LOW);   // D = 0
            break;

        case 5:
            digitalWrite(A2, LOW);   // A = 0
            digitalWrite(B2, LOW);   // B = 0
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, LOW);   // D = 0
            break;

        case 6:
            digitalWrite(A2, HIGH);  // A = 1
            digitalWrite(B2, LOW);   // B = 0
            digitalWrite(C2, LOW);   // C = 0
            digitalWrite(D2, HIGH);  // D = 1
            break;

        case 7:
            digitalWrite(A2, LOW);   // A = 0
            digitalWrite(B2, HIGH);  // B = 1
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, HIGH);  // D = 1
            break;

        case 8:
            digitalWrite(A2, HIGH);  // A = 1
            digitalWrite(B2, HIGH);  // B = 1
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, HIGH);  // D = 1
            break;

        case 9:
            digitalWrite(A2, LOW);   // A = 0
            digitalWrite(B2, LOW);   // B = 0
            digitalWrite(C2, HIGH);  // C = 1
            digitalWrite(D2, HIGH);  // D = 1
            break;
    }
}