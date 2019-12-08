function [x_opt] = solve_HW6_LP_full(A,b,c)
% Full LP solver
% 
% WTJ, 20180810

[m, n] = size(A);
x_opt = NaN;

%% phase I
isfeasible = false;
x0 = A\b;
x0_min = min(x0);
if x0_min > 0
    isfeasible = true;
else
    t0 = 2 - x0_min;
    z0 = x0 + (t0-1)*ones(n, 1);
    c1 = [zeros(n, 1); 1];
    A1 = [A, -A*ones(n,1)];
    b1 = b - A*ones(n,1);
    z1 = [z0; t0];
    [z_opt] = solve_HW6_LP_barrier(A1, b1, c1, z1);
    if z_opt(end) < 1
        isfeasible = true;
    end
end

if ~ isfeasible
    return;
end

%% phase II
t = z_opt(end);
x0 = z_opt(1:(end-1)) - (t-1)*ones(n,1);
[x_opt] = solve_HW6_LP_barrier(A, b, c, x0);

end