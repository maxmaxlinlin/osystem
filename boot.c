typedef void (*init_func)(void); //3-7
// function pointer type, pointing to a function returning nothing (void), 
//not taking any parameters and naming the new type init_func.
#define UFCONO ((volatile unsigned int *)(0x50000020))

void helloworld(void){
	const char *p="helloworld\n";
	while(*p){
		*UFCONO=*p++;
	};
}



static init_func init[]={ //3-6
	helloworld,
	0,
};

void plat_boot(void){
	int i;
	for(i=0;init[i];i++){
		init[i]();
	}
	while(1);
}