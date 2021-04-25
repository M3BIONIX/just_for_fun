#!/usr/bin/env python
# coding: utf-8

# In[52]:


import torch
import torch.nn as nn
import numpy as np
from sklearn import datasets
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split


# In[53]:


#Loading Data
bc = datasets.load_breast_cancer()
x,y=bc.data, bc.target
n_samples,n_features = x.shape
print(n_samples," ",n_features)


# In[54]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size = 0.2,random_state=1234)
sc = StandardScaler()
x_train = sc.fit_transform(x_train)
x_test = sc.transform(x_test)
x_train = torch.from_numpy(x_train.astype(np.float32))
x_test = torch.from_numpy(x_test.astype(np.float32))
y_train = torch.from_numpy(y_train.astype(np.float32))
y_test = torch.from_numpy(y_test.astype(np.float32))
y_train = y_train.view(y_train.shape[0],1)
y_test = y_test.view(y_test.shape[0],1)


# In[55]:


#Model 
class LogisticReg(nn.Module):
    def __init__(self,n_input_features):
        super(LogisticReg,self).__init__()
        self.lin = nn.Linear(n_input_features, 1)
    def forward(self , x):
        ypred = torch.sigmoid(self.lin(x))
        return ypred 

    
model = LogisticReg(n_features)


# In[56]:


#loss
loss = nn.BCELoss()
optimizer = torch.optim.SGD(model.parameters(), lr = 0.01)


# In[57]:


#Training 
n_iters = 100000
for i  in range(n_iters):
    y_pred = model(x_train)
    l = loss(y_pred,y_train)
    l.backward()
    optimizer.step()
    optimizer.zero_grad()
    print(f'Iteration {i+1}  loss = {l:.3f} ') 
     
with torch.no_grad():
    y_pred = model(x_test)
    y_pred_cls = y_pred.round()
    acc = y_pred_cls.eq(y_test).sum()/float(y_test.shape[0])


# In[58]:


print(f"Accuracy = {acc:.3f}")


# In[ ]:




