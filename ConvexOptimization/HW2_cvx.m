
%% 4.1 a
cvx_begin
variables x1 x2
minimize(x1+x2)
subject to
2 * x1 + x2 >= 1
x1 + 3 * x2 >= 1
x1 >= 0
x2 >= 0
cvx_end
% Status: Solved
% Optimal value (cvx_optval): +0.6

%% 4.1 b
cvx_begin
variables x1 x2
minimize(-x1-x2)
subject to
2 * x1 + x2 >= 1
x1 + 3 * x2 >= 1
x1 >= 0
x2 >= 0
cvx_end
% Status: Unbounded
% Optimal value (cvx_optval): -Inf

%% 4.1 c
cvx_begin
variables x1 x2
minimize(x1)
subject to
2 * x1 + x2 >= 1
x1 + 3 * x2 >= 1
x1 >= 0
x2 >= 0
cvx_end
% Status: Solved
% Optimal value (cvx_optval): +8.45293e-10

%% 4.1 d
cvx_begin
variables x1 x2
minimize(max(x1,x2))
subject to
2 * x1 + x2 >= 1
x1 + 3 * x2 >= 1
x1 >= 0
x2 >= 0
cvx_end
% Status: Solved
% Optimal value (cvx_optval): +0.333333

%% 4.1 e
cvx_begin
variables x1 x2
minimize(x1^2 + 9*x2^2)
subject to
2 * x1 + x2 >= 1
x1 + 3 * x2 >= 1
x1 >= 0
x2 >= 0
cvx_end
% Status: Solved
% Optimal value (cvx_optval): +0.5
