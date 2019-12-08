randn('seed', 1); 
T = 96; % 15 minute intervals in a 24 hour period
t = (1:T)'; 
p = exp(-cos((t-15)*2*pi/T)+0.01*randn(T,1)); 
u = 2*exp(-0.6*cos((t+40)*pi/T) -0.7*cos(t*4*pi/T)+0.01*randn(T,1));
figure;
plot(t/4, p); 
hold on
plot(t/4,u,'r');

%
Q = 35; C = 3; D = -3;
%%
cvx_begin
variable c(T)
variable q(T)
minimize(p'*(u+c))
subject to
0<=q<=Q;
D<=c<=C;
sum(c)==0;
q(2:T)==q(1:T-1) + c(1:T-1);
q(1)==q(T)+c(T);
u+c>=0;
cvx_end

%%
plot(t/4, c);
plot(t/4, q);
legend({'p','u','c','q'});

%% total cost versus capacity
vs_C3D3 = [];
vs_C1D1 = [];
Qs = [1:10:200];
for ii = 1:length(Qs)
    Q = Qs(ii);
    [v, c, q] = cvx_solve_c_q(Q, 3, -3);
    vs_C3D3(ii) = v;
    [v, c, q] = cvx_solve_c_q(Q, 1, -1);
    vs_C1D1(ii) = v;    
end

figure;
plot(Qs, vs_C3D3);
hold all;
plot(Qs, vs_C1D1);
xlabel('storage capacity');
ylabel('min total cost');
legend({'C=3,D=-3','C=1,D=-1'})

%%
function [cvx_optval, c, q] = cvx_solve_c_q(Q, C, D)
randn('seed', 1); 
T = 96; % 15 minute intervals in a 24 hour period
t = (1:T)'; 
p = exp(-cos((t-15)*2*pi/T)+0.01*randn(T,1)); 
u = 2*exp(-0.6*cos((t+40)*pi/T) -0.7*cos(t*4*pi/T)+0.01*randn(T,1));

cvx_begin
variable c(T)
variable q(T)
minimize(p'*(u+c))
subject to
0<=q<=Q;
D<=c<=C;
sum(c)==0;
q(2:T)==q(1:T-1) + c(1:T-1);
q(1)==q(T)+c(T);
u+c>=0;
cvx_end
end