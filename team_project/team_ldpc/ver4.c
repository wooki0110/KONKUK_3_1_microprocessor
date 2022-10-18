void ldpcd_opt(float(*NLLR)[N], float** opt_out) {

	///////////////////////
	// Edit code below!! //

	//동적할당은 정확성만 낮아지
	//float * Zxn = (float *)calloc((Z*Mp)*(Z*Np),sizeof(float));
	//float * Zn = (float *)calloc((Z * Np),sizeof(float));
	//float * Lxn = (float *)calloc((Z*Mp)*(Z*Np),sizeof(float));

	float Zn[Z * Np] = { 0, };  // final Value L
	int tp[Z * Mp][Z * Np] = { 0, };
	float a = 0;
	int count[Z * Np] = { 0, };
	int ct;

	for (int p = 0; p < WC; p++) {
		for (int j = 0; j < Z * Np; j++) {
			Zn[j] = NLLR[p][j];
		}
		float Zxn[Z * Mp][Z * Np] = { 0, };		//초기화 시마다 배열 새로 선언
		float Lxn[Z * Mp][Z * Np] = { 0, };		//초기화 시마다 배열 새로 선언

		for (int k = 0; k < iter; k++) { 
			for (int j = 0; j < M; j++) {
				float min1 = 500;  //가장 최소값
				float min2 = 500;  //두번째 최소값
				int minx = 0;		//첫번째 최소값 위치 저장
				int sgn = 1;		//부호저장
				int t = 0;			//H배열이 1인 배열의 i값 저장
				if (k == 0) {
					ct = 0;
					for (int i = 0; i < N; i++) {
						if (H[j][i] == 1)
							tp[j][ct++] = i;
					}
					count[j] = ct;
				}
				for (int r = 0; r < count[j]; r++) {
					t = tp[j][r];
					Zxn[j][t] = Zn[t] - Lxn[j][t];
					if (Zxn[j][t] < 0) {
						sgn = sgn * -1;
					}
					a = fabs(Zxn[j][t]);
					if (min1 > a) {
						min2 = min1;
						min1 = a;
						minx = t;
					}
					else if (min2 > a)
						min2 = a;
				}

				//sel step
				for (int r = 0; r < count[j]; r++) {
					t = tp[j][r];
					if (minx == t) {
						if (min2 > Offset) {
							Lxn[j][t] = min2 - Offset;
						}
						else {
							Lxn[j][t] = 0;
						}
					}
					else {
						if (min1 > Offset) {
							Lxn[j][t] = min1 - Offset;
						}
						else {
							Lxn[j][t] = 0;
						}
					}
					if (Zxn[j][t] >= 0) {
						Lxn[j][t] = Lxn[j][t] * sgn;
					}
					else
						Lxn[j][t] = Lxn[j][t] * sgn * -1;

					Zn[t] = Zxn[j][t] + Lxn[j][t];
				}
			}
		}

		/* output before Hard Decision */
		for (int i = 0; i < MAX_LENGTH; i++)
			opt_out[p][i] = Zn[i];
	}

	// Edit code above!! //
	///////////////////////
}