

%% problem A3.18
rand('state',0);
n=100;
m=300;
A=rand(m,n);
b=A*ones(n,1)/2;
c=-rand(n,1);

%% CVX
cvx_begin
variable x(n)
minimize(c'*x)
subject to 
0<=x<=1;
A*x<=b;
cvx_end

%% check results
figure;
subplot(1,2,1);
plot(x);
xlabel('n');
ylabel('x');
subplot(1,2,2);
hold all;
plot(A*x);
plot(b);
plot(b-A*x);
legend({'Ax','b','b - Ax'});

%% now threshold x by t and plot objective and max violation
ts = linspace(0,1,100);
maxVlts = [];
objVals = [];
figure;
subplot(1,2,1);
hold all;
subplot(1,2,2);
hold all;
for ii = 1:length(ts)
    t = ts(ii);
    x_bool = x >= t;
    maxVlt = max(A*x_bool - b);
    maxVlts(ii) = maxVlt;
    objVals(ii) = c'*x_bool;
    if maxVlt > 0
        subplot(1,2,1);
        stem(t, objVals(ii), 'r');
        subplot(1,2,2);
        stem(t, maxVlts(ii), 'r');
    else
        subplot(1,2,1);
        stem(t, objVals(ii), 'b');
        subplot(1,2,2);
        stem(t, maxVlts(ii), 'b');
    end
end

subplot(1,2,1);
xlabel('t');
ylabel('objective values');
subplot(1,2,2);
ylabel('max violations');
xlabel('t');

%% find min obj val where x is still feasible
inds_feasible = maxVlts <= 0;
[minObj, ind_min] = min(objVals(inds_feasible));
ts_feasible = ts(inds_feasible);
t_minObj = ts_feasible(ind_min);
x_minObj = x >= t_minObj;
L = c'*x
U = c'*x_minObj

%% A3.20
veh_speed_sched_data;
cvx_begin
variable t(n)
minimize(a*(d.^2)'*inv_pos(t) + b*sum(d) + c* sum(t));
subject to 
tau_min<=cumsum(t)<=tau_max;
d./smax<=t<=d./smin;
cvx_end

%% plot results
figure;
stairs(d./t);
xlabel('segments')
ylabel('speed')

%% A5.2
k = 201;
is = 1:k;
t = -3 + 6*(is-1)/(k-1);
y = exp(t);
l = 0; u = exp(3);
tol = 0.001;
while (abs(l-u) > tol)
    gamma = (l+u)/2;
    cvx_begin
    variables a0 a1 a2 b1 b2
    subject to 
    abs(a0+a1*t+a2*t.^2-y.*(1+b1*t+b2*t.^2))<=gamma*(1+b1*t+b2*t.^2)
    cvx_end
    if strcmp(cvx_status,'Solved')
        u = gamma;
    else
        l = gamma;
    end
end
[a0 a1 a2 b1 b2]

%% plot
figure;
subplot(1,2,1)
plot(t, y,'.')
hold all
plot(t, (a0+a1*t+a2*t.^2)./(1+b1*t+b2*t.^2))
subplot(1,2,2)
plot(t, (a0+a1*t+a2*t.^2)./(1+b1*t+b2*t.^2) - y)


%% A13.3
simple_portfolio_data;

% risk of the uniform portfolio
x_unif'*S*x_unif

% no constraint
cvx_begin
variable x(n)
minimize(x'*S*x)
subject to
sum(x) == 1
pbar'*x == pbar'*x_unif
cvx_end
var_noConst = cvx_optval;

% long-only
cvx_begin
variable x(n)
minimize(x'*S*x)
subject to
pbar'*x == pbar'*x_unif
sum(x) == 1
x >= 0
cvx_end
var_longOnly = cvx_optval;

% limit on total short
cvx_begin
variable x(n)
minimize(x'*S*x)
subject to
pbar'*x == pbar'*x_unif
sum(x) == 1
sum(max([-x, zeros(n,1)]')) <= 0.5
cvx_end
var_totShort = cvx_optval;

%% plot the optimal risk-return trade-off curves
% long only
mus = [0:0.1:1, 2:1:10];
mean_rets = [];
var_rets = [];
for ii = 1:length(mus)
    mu = mus(ii)
    cvx_begin
    variable x(n)
    minimize(-pbar'*x+mu*x'*S*x)
    subject to
    sum(x) == 1
    x >= 0
    cvx_end
    mean_rets(ii) = pbar'*x;
    var_rets(ii) = x'*S*x;
end



%% tot short less than 0.5
mus = [0:0.1:1, 2:1:10];
mean_rets_TSL = [];
var_rets_TSL = [];
for ii = 1:length(mus)
    mu = mus(ii)
    cvx_begin
    variable x(n)
    minimize(-pbar'*x+mu*x'*S*x)
    subject to
    sum(x) == 1
    sum(max([-x, zeros(n,1)]')) <= 0.5
    cvx_end
    mean_rets_TSL(ii) = pbar'*x;
    var_rets_TSL(ii) = x'*S*x;
end


%% plot
figure;
plot(var_rets, mean_rets);
xlabel('variance');
ylabel('mean return');
hold all;
plot(var_rets_TSL, mean_rets_TSL);
legend({'Long only','Total short limit'})



