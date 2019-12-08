% HW 6

%% 9.30

alpha = 0.25;
beta = 0.5;
m = 50;
n = 100;
%% plot
figure;
subplot(231)
[p, fx_all] = solve_HW6_9_30(m, n, alpha, beta);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m,n,alpha,beta))

subplot(232)
[p, fx_all] = solve_HW6_9_30(m*2, n, alpha, beta);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m*2,n,alpha,beta))


subplot(233)
[p, fx_all] = solve_HW6_9_30(m*2, n*2, alpha, beta);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m*2,n*2,alpha,beta))


subplot(234)
[p, fx_all] = solve_HW6_9_30(m, n, 0.2, beta);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m,n,0.2,beta))


subplot(235)
[p, fx_all] = solve_HW6_9_30(m, n, 0.1, beta);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m,n,0.1,beta))


subplot(236)
[p, fx_all] = solve_HW6_9_30(m, n, 0.25, 0.8);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d\nalpha=%.2f, beta=%.2f',m,n,0.25,0.8))

%% 9.30 b

figure;
subplot(131)
[p, fx_all] = solve_HW6_9_30_b(m, n);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d',m,n))

subplot(132)
[p, fx_all] = solve_HW6_9_30_b(m*2, n*2);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d',m*2,n*2))


subplot(133)
[p, fx_all] = solve_HW6_9_30_b(m*4, n*2);
semilogy(fx_all - p)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d',m*4,n*2))




%% 9.31
% (a)

A = 2*rand(m*4, n*2) - ones(m*4, n*2);
[p_1, fx_all_1] = solve_HW6_9_31(A, m*4, n*2, 1);
[p_2, fx_all_2] = solve_HW6_9_31(A, m*4, n*2, 2);
[p_5, fx_all_5] = solve_HW6_9_31(A, m*4, n*2, 5);

figure;
semilogy(fx_all_1-p_1)
hold all
semilogy(fx_all_2-p_2)
semilogy(fx_all_5-p_5)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d',m*4,n*2))
legend({'Newton', 'N_{reuse}=2', 'N_{reuse}=5'});


%% (b) compare diagonal approx and Newton

A = 2*rand(m*4, n*2) - ones(m*4, n*2);
[p_1, fx_all_newton] = solve_HW6_9_31(A, m*4, n*2, 1);
[p_2, fx_all_diagApprox] = solve_HW6_9_31_b(A, m*4, n*2);

figure;
semilogy(fx_all_newton-p_1)
hold all
semilogy(fx_all_diagApprox-p_2)
xlabel('iterations')
ylabel('f(x) - p')
title(sprintf('m=%d,n=%d',m*4,n*2))
legend({'Newton', 'Diag. approx.'});


%% A6.5
nonlin_meas_data;

cvx_begin;
variables x(n) z(m)
minimize(norm(z-A*x))
subject to
(y(2:m) - y(1:(m-1)))/beta <= z(2:m) - z(1:(m-1)) ;
z(2:m) - z(1:(m-1)) <= (y(2:m) - y(1:(m-1)))/alpha;


cvx_end;

%% plot z_ml
figure;
plot(z, y)
hold all;
plot(A*x, y, '.');
xlabel('z');
ylabel('y');
legend({'y vs. z','y vs. A*x'});


%% A9.5
%% different instances

m = 200;
n = 300;

figure;
subplot(121)
for nn = 1:5
% generate data
A = 2*rand(m, n) + 2*[diag(ones(1, m )), zeros(m, n-m)];
x0 = rand(n, 1);
b = A*x0;
c = rand(n,1);

% solving
[x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0);

% plotting
semilogy(1:N_steps, lambdasqs); hold all;
xlabel('iterations');
ylabel('\lambda^2/2');
end

%% try same instance with different alpha and beta
lgds = {};

subplot(122);
alf = 0.1;
beta = 0.5;
[x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0, alf, beta);
semilogy(1:N_steps, lambdasqs); hold all;
lgds{end+1} = sprintf('\\alpha = %.2f, \\beta = %.2f', alf, beta);

alf = 0.25;
beta = 0.5;
[x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0, alf, beta);
semilogy(1:N_steps, lambdasqs); hold all;
lgds{end+1} = sprintf('\\alpha = %.2f, \\beta = %.2f', alf, beta);

alf = 0.25;
beta = 0.2;
[x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0, alf, beta);
semilogy(1:N_steps, lambdasqs); hold all;
lgds{end+1} = sprintf('\\alpha = %.2f, \\beta = %.2f', alf, beta);

alf = 0.1;
beta = 0.2;
[x_opt, v_opt, N_steps, lambdasqs] = solve_HW6_LP_CS(A, b, c, x0, alf, beta);
semilogy(1:N_steps, lambdasqs); hold all;
lgds{end+1} = sprintf('\\alpha = %.2f, \\beta = %.2f', alf, beta);

xlabel('iterations');
ylabel('\lambda^2/2');
legend(lgds);

% check KKT:
df = c - 1./x_opt;
norm(df + A'*v_opt)


%% (b), barrier

m = 100;
n = 500;

% generate data
A = 2*rand(m, n) + 2*[diag(ones(1, m )), zeros(m, n-m)];
x0 = rand(n, 1);
b = A*x0;
c = rand(n,1);
% solve
[x_opt, history] = solve_HW6_LP_barrier(A, b, c, x0);

%% plot
figure;
[xx, yy] = stairs(cumsum(history(1,:)),history(2,:));
semilogy(xx,yy);hold all;
lgds = {'\mu=2'};
for mu = [5, 20, 50]
    mu
[x_opt, history] = solve_HW6_LP_barrier(A, b, c, x0, mu);
[xx, yy] = stairs(cumsum(history(1,:)),history(2,:));
semilogy(xx,yy);hold all;
lgds{end+1} = sprintf('\\mu=%d',mu);
end
legend(lgds)
xlabel('Newton iterations');
ylabel('duality gap (= n/t)');

%% check with CVX:
cvx_begin
variable x(n)
minimize(c'*x)
subject to
A*x == b;
x >= 0;
cvx_end

disp(norm(x-x_opt))

%% (c), full LP solver:

m = 100;
n = 500;
% this is likely infeasible
A = 2*rand(m, n) + 2*[diag(ones(1, m )), zeros(m, n-m)];
b = rand(m,1);
c = rand(n,1);

% manually generate a feasible instance:

A = 2*rand(m, n) + 2*[diag(ones(1, m )), zeros(m, n-m)];
x0 = rand(n, 1);
b = A*x0;
c = rand(n,1);

%% written solver:
x_opt = solve_HW6_LP_full(A,b,c);
%% cvx:
cvx_begin
variable x(n)
minimize(c'*x)
subject to
A*x == b;
x >= 0;
cvx_end

% compare
disp(norm(x-x_opt))











