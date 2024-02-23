#ifndef _JUMPING_LIKE_JOIN
#define _JUMPING_LIKE_JOIN

#include "../KVstore/KVstore.h"
#include "../Util/Util.h"
#include "TempResult.h"

class JumpingLikeJoin
{
private:
  KVstore* kvstore;
  string pre;

  //use array
  unsigned* sub_obj_list;
  unsigned sub_obj_list_size;
  map<unsigned, unsigned> sub2posOfEdgeOne;
  map<unsigned, unsigned> sub2posOfEgdeJoined;

  

  //based on map.
  std::map<unsigned int, std::vector<unsigned int> > edgeTable;
  std::map<unsigned int, std::vector<unsigned int*> > subTable;

  std::map<unsigned int, TempResultSet*> intermediate;
public:

  TempResultSet* edge2;
  TempResultSet* edge3;

  JumpingLikeJoin(KVstore* _kvstore,string _pre):kvstore(_kvstore), pre(_pre)
  {}

  TYPE_PREDICATE_ID getPreID(std::string pre);
  TYPE_ENTITY_LITERAL_ID getEntityID(std::string entity);

  //function based on array.
  void initSub2Pos(TYPE_PREDICATE_ID preid);
  void buildSubTableUsedArray(TempResultSet *temp);
  TempResultSet* intersectUsedArray(TempResultSet *temp);

  // functions based on map.
  void initEdgeTable(TYPE_PREDICATE_ID preid);
  void initEdgeTable1(TYPE_PREDICATE_ID preid);
  void buildSubTable(TempResultSet *temp);
  int bfsByHops(int hops);
  TempResultSet* getEdge2ByEgde1();
  TempResultSet* getEdge3ByEgde1();
  TempResultSet* getEdge4ByEgde1();
  TempResultSet* getEdge3ByEgde1(TYPE_ENTITY_LITERAL_ID id); // 常量开头的3边路径
  TempResultSet* intersect(TempResultSet* temp2); // TempResultSet *temp1 is removed, temp joins len1 
  TempResultSet* intersect1(TempResultSet* temp2); // len1 joins temp
  TempResultSet* intersect(TYPE_ENTITY_LITERAL_ID id, TempResultSet* temp2); // TempResultSet *temp1 is removed
  TempResultSet* intersect(TempResultSet* temp1, TempResultSet* temp2);

  // 3跳
  static void *run(void *args);
  // 2跳 
  static void *run1(void *args);
  // 4跳 
  static void *run4(void *args);
  // 5跳 
  static void *run5(void *args);
  // 6跳 
  static void *run6(void *args);
  // 7跳 
  static void *run7(void *args);
};

#endif //_JUMPING_LIKE_JOIN