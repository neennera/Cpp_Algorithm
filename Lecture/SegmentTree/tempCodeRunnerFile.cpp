
        cout << l <<"," << r << "\n";
        if(l>=ql&&r<=qr){
            lazy[node]=k;
            prop(node,l,r);
        }

        int child=node*2, m=(l+r)>>1;
        update(child,k,l,m,ql,qr);
        update(child+1,k,m+1,r,ql,qr);

        seg[node]=min(seg[child],seg[child+1]);
    }

    int get_value(int node,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return INT_MAX;
        if(l==r){
            prop(node,l,r);
            return seg[node];
        }

        prop(node,l,r);
        int child=node*2, m=(l+r)>>1;
        return min(get_value(child,l,m,ql,qr),get_value(child+1,m+1,r,ql,qr));
    }

    void pf(){
        cout << "\npf(); \n";
        for(int i=1;i<2*C;i++){
            for(int j=i;j<2*i;j++){
                cout << seg[i] << " ";
            }
            cout << endl;
        }

        for(int i=1;i<2*C;i++){
            for(int j=i;j<2*i;j++){
                cout << lazy[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){