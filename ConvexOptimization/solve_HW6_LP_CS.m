function [x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0, alpha, beta)
% Solve LP with centering step
% Example data:
% 
%     m = 200;
%     n = 300;
%     A = 2*rand(m, n) + 2*[diag(ones(1, m )), zeros(m, n-m)];
%     x0 = rand(n, 1);
%     b = A*x0;
%     c = rand(n,1);
% 
% WTJ, 20180810


x = x0;
n_iter = 500;
if nargin < 6
beta = 0.5;
end
if nargin < 5
alpha = 0.25;
end
x_opt = NaN;
v_opt = NaN;
lambdasqs = [];
N_steps = 0;
tol = 1e-3;

if (min(x0) <= 0 || norm(A*x0 - b) > tol)
    return;
end

for ii = 1:n_iter
%     X = diag(1./(x.^2));
    N_steps = ii;
    X_inv = diag(x.^2);
    df = c - 1./x;
    B = -df;
    % w from block elimination
    w = (A*X_inv * A')\(A*X_inv*B);
    dx_nt = X_inv * (B - A' * w);
    lambdasq = -dx_nt' * df;
    lambdasqs(ii) = lambdasq/2;
    if lambdasq < tol
        x_opt = x;
        v_opt = w;
        return;
    end
    % line search
    t = 1;
    while min(x+t*dx_nt) <= 0
        t = beta * t;
    end
    
    while get_fx(x + t*dx_nt) >= get_fx(x) + alpha * t * (df' * dx_nt)
        t = beta * t;
    end
    x = x + t*dx_nt;
end

function f = get_fx(x)
    f = c'*x - sum(log(x));    
end

end
