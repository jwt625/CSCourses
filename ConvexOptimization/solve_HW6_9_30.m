
function [p, fx_all] = solve_HW6_9_30(m, n, alpha, beta)
% alpha = 0.25;
% beta = 0.5;
% m = 50;
% n = 100;
% A = 2*rand(m, n) - ones(m, n);
A = 2*rand(m, n);% - ones(m, n);
tol = 1e-5;
n_maxiter = 500;
% initial x
x = zeros(n,1);
fx_all = NaN(1, n_maxiter);
x_all = NaN(n, n_maxiter);
ps = NaN(1, n_maxiter);
p = 1;
for ii = 1:n_maxiter
    fx = - sum(log(1-A*x)) - sum(log(1-x.^2));
    fx_all(ii) = fx;
    x_all(:,ii) = x;
    ps(ii) = p;
    df = A' * (1./(1 - A*x)) - 1./(1+x) + 1./(1-x);
    if norm(df) < tol
        p = fx;
        break;
    end
    if fx < p
        p = fx;
    end
    dx = -df;
    t = 1;
    while (max(A*(x + t*dx) ) >= 1) || (max(abs((x + t*dx))) >= 1)
        t = t * beta;
    end
    while (- sum(log(1-A*(x + t*dx))) - sum(log(1-(x + t*dx).^2)) ) >...
            (fx + alpha * t * df'*dx )
        t = t * beta;
    end
    x = x + t * dx;
end

end