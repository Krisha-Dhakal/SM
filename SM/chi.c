#include <stdio.h>

struct ChiSquare {
    int n;
    int observed[20];
    int i;
    int N;
    int Expected;
    float Calculation[20];
    float final;
    float critical;
};

void getdata(struct ChiSquare *c) {
    printf("How many numbers?: ");
    scanf("%d", &c->n);
    printf("Enter the observed frequency:\n");
    for (c->i = 0; c->i < c->n; c->i++) {
        printf("Enter %dth number: ", c->i + 1);
        scanf("%d", &c->observed[c->i]);
    }
}

void calculation(struct ChiSquare *c) {
    for (c->i = 0; c->i < c->n; c->i++) {
        c->N = c->N + c->observed[c->i];
    }
    c->Expected = c->N / c->n;
    for (c->i = 0; c->i < c->n; c->i++) {
        c->Calculation[c->i] = (float)((c->observed[c->i] - c->Expected) * (c->observed[c->i] - c->Expected)) / c->Expected;
        c->final = c->final + c->Calculation[c->i];
    }
}

void display(struct ChiSquare *c) {
	printf("-------------------------------------------------------\n");
    printf("%5s\t%5s\t%5s\t%-22s\n", "S.No", "Oi", "Ei", "((Oi-Ei)*(Oi-Ei))/Ei");
    for (c->i = 0; c->i < c->n; c->i++) {
        printf("%5d\t%5d\t%5d\t%10.2f\n", c->i + 1, c->observed[c->i], c->Expected, c->Calculation[c->i]);
    }
    printf("-------------------------------------------------------\n");
    printf("    %10d\t  %15.2f\n", c->N, c->final);
}

void conclusion(struct ChiSquare *c) {
    printf("\nEnter the critical value:\n");
    scanf("%f", &c->critical);
    if (c->final < c->critical) {
        printf("The test is accepted\n");
    } else {
        printf("The test is rejected\n");
    }
}

int main() {
    struct ChiSquare c;
    c.N = 0;
    c.final = 0.00;
    getdata(&c);
    calculation(&c);
    display(&c);
    conclusion(&c);

    return 0;
}
