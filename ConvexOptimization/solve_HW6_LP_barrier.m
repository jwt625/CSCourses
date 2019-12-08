function [x_opt, history] = solve_HW6_LP_barrier(A, b, c, x0, mu)
% Solving LP with eq constraint using barrier
% 
% WTJ, 20180810
t = 1;
if nargin < 5
mu = 2;
end
n_iter = 500;
x_opt = [];
history = NaN(2, n_iter);
tol_dualgap = 1e-3;
n = length(x0);
for ii = 1:n_iter    
    g = n/t;
    [x, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c*t, x0);
    history(1, ii) = N_steps;
    history(2, ii) = g;    
    if g < tol_dualgap
        x_opt = x;
        return
    end
    t = t * mu;    
end
end