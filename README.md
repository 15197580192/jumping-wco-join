# jumping-wco-join
This is the code of the paper:Variable-length Path Query Evaluation based on Worst-Case Optimal Joins.Here we present how we embed our jumping-like worst-case optimal join technique in [gStore](https://github.com/pkumod/gStore).

## Install
System Requirement: 64-bit linux server with gcc and g++ 5.0 or later.
First,we install the environment and compire gStore.If you are an Ubuntu user, you can execute the following command:
```
. scripts/setup/setup_ubuntu.sh
make pre
make
```

## Excute
### Create database
We load RDF datasets in NT format in gStore.
```
bin/gbuild db_name nt_file
```
### Query
Our method is embedded into query execution,so excute query to use our method.
```
bin/gquery db_name query_file
```
