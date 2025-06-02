#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CPU25.h"
#include "RAM25.h"



Instrucao* setPrograma(CPU *cpu, Instrucao *programaAux){
    return cpu->programa = programaAux;
}

void iniciarCPU(CPU *cpu){
    cpu->pc = 0;
    int opcode = 0; //só existe na função

    while(opcode != -1){
        
        Instrucao inst = cpu->programa[cpu->pc]; //Ou seja, como pc é zero, programa[0] que quer dizer que vai executar o primeiro programa
        opcode = inst.opcode;//pego a entrada do opcode e coloco no opcode local
			//-1 -> halt
			// 0 -> soma
			// 1 -> subtrai
			// 2 -> copia do registrador para RAM
			// 3 -> copia da RAM para o registrador
			// 4 -> salva conteudo externo no registrador
			// 5 -> obtem conteudo externo do registrador
        switch(opcode){
            case -1: {
                printf("programa terminou!\n");
                break;
            }//halt

            case 0: {
                cpu->registrador1 = getDado(inst.add1);
                cpu->registrador2 = getDado(inst.add2);
                cpu->registrador1 += cpu->registrador2; //salva resultado
                setDado(inst.add3, cpu->registrador1);
                printf("Inst sum -> RAM posicao %d com conteudo %d\n", inst.add3, cpu->registrador1);
                break;
            }//soma

            case 1: {
                cpu->registrador1 = getDado(inst.add1);
                cpu->registrador2 = getDado(inst.add2);
                cpu->registrador1 -= cpu->registrador2; //salva resultado
                setDado(inst.add3, cpu->registrador1);
                printf("Inst sub -> RAM posicao %d com conteudo %d\n", inst.add3, cpu->registrador1);
                break;
            }//subtracao

            case 2: {
                if(inst.add1==1){
                    setDado(inst.add2, cpu->registrador1);
                    printf("Inst copy reg to ram -> RAM posicao %d com conteúdo %d\n", inst.add2, cpu->registrador1);
                }else if(inst.add1==2){
                    setDado(inst.add2, cpu->registrador2);
                    printf("Inst copy reg to ram -> RAM posicao %d com conteudo %d\n", inst.add2, cpu->registrador2);
                }
                break;
            }

            case 3: {
                if(inst.add1==1){
                    cpu->registrador1 = getDado(inst.add2);
                    printf("Inst copy ext reg -> Registrador1 com conteudo %d\n", cpu->registrador1);
                }else if(inst.add1==2){
                    cpu->registrador2 = getDado(inst.add2);
                    printf("Inst copy ext reg -> Registrador2 com conteudo %d\n", cpu->registrador2);
                }break;
            }

            case 4: {
                if (inst.add1==1)
                {
                    cpu->registrador1 = inst.add2;
                    printf("Inst copy_ext_reg -> Registrador1 com conteudo %d\n", cpu->registrador1);
                }
                else if (inst.add1 == 2)
                {
                    cpu->registrador2 = inst.add2;
                    printf("Inst copy_ext_reg -> Registrador2 com conteudo %d\n", cpu->registrador2);
                }
                break;
                
                
            }

            case 5: {
                if(inst.add1==1){
                    inst.add2 = cpu->registrador1;
                    printf("Inst obtain reg -> Registrador1 com conteúdo %d\n", cpu->registrador1);
                } else if(inst.add1==2){
                    inst.add2 = cpu->registrador2;
                    printf("Inst obtain reg -> Registrador2 com conteúdo %d\n", cpu->registrador2);  
                }
                break;
            }
        }
        cpu->pc++;
    }
}
          


    


