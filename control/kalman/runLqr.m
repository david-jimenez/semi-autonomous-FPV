function [K,X,L] = runLqr(A,B,Q,R,asd)
	#disp(typeinfo(A));
	#disp(typeinfo(B));
	#disp(typeinfo(Q));
	#disp(typeinfo(R));
	#disp(A);
	#disp(B);
	#disp(Q);
	#disp(R);	
	[K, X, L] = lqr(A,B,Q,R);
	#disp("Hello");
	#disp(K);
	#disp(X);
	#disp(L);
endfunction
