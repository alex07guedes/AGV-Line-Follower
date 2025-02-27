#ifndef ENCODERS_H_
#define ENCODERS_H_

	extern volatile float velocidade_esq;
	extern volatile float velocidade_dir;
	extern volatile unsigned int voltas_esq;
	extern volatile unsigned int voltas_dir;

	void init_encoders();
	void init_timer1();

#endif /* ENCODERS_H_ */
