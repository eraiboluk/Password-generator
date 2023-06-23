#include <stdio.h>

char* password_generator(char a, char b, int haz, char* pass){
    char cha[2];
    cha[0]=a;
    cha[1]=b;
    int val1=cha[0],  val2=cha[1], before=haz;
				
		if(val1>96)
			pass[0]=cha[0]-32;
		else
			pass[0]=cha[0];
				

        for(int i=1;i<8;i++){
            before=(((before*haz)+val1)/val2) % 126;
            if(before<33)
                pass[i]=before+33;
            else
                pass[i]=before;      	
		}
        return pass;
}

int main() {
    FILE *file;
    char pass[6];
    int haz, cho;

    file = fopen("haphazard.txt", "r");
    fscanf(file, "%d", &haz);
    fclose(file);

    printf("Welcome to the Password Manager!\n");
    printf("\n");
    printf("Your haphazard number is: %d\n", haz);
    printf("\n");
    printf("Possible passwords:\n");
    printf("\n");
    printf("Instagram: %.8s\n", password_generator('i','n',haz, pass));
    printf("Twitter: %.8s\n", password_generator('t','w',haz, pass));
    printf("Facebook: %.8s\n", password_generator('f','a',haz, pass));
    printf("Github: %.8s\n", password_generator('g','i',haz, pass));
    printf("Google: %.8s\n", password_generator('g','o',haz, pass));
    printf("\n");

    do {
        // Menüyü göster
        printf("1. Change the number\n");
        printf("2. Perform encryption\n");
        printf("3. Exit\n");

        // Kullanıcının seçimini al
        printf("Which choice?: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1:
                // Değeri değiştir
                printf("\nEnter a new number: \n");
                printf("NOTE: Your number must not exceed 4*10^5. \n");
                scanf("%d", &haz);

                // deger.txt dosyasına yeni değeri yaz
                file = fopen("haphazard.txt", "w");
                fprintf(file, "%d", haz);
                fclose(file);

                printf("Success...\n");
                break;
            case 2:{
			
                char cha[2];

                printf("\nWelcome to the encryption service. \nPlease enter the first 2 letters of the service or site you want to create a password for.\n");
                scanf("%s", cha);

                printf("Your generated password is: %.8s\n", password_generator(cha[0], cha[1], haz, pass));
                
                break;
                }
            case 3:
                // Çıkış
                printf("\nExiting...\n");
                break;
            default:
                printf("\nThere is no such number (%d) on the menu\n",cho);
                break;
        }

        printf("\n");
        
    } while (cho != 3);

    return 0;
}