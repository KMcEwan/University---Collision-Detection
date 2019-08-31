//#include "QuadT.h"
//
//Node* QuadT::BuildQuadtree (vec2 centre, float halfWidth, int stopDepth)
//	{
//		if (stopDepth < 0) return nullptr;
//
//		else
//		{
//			Node* pNode = new Node;
//			pNode->center = centre;
//			pNode->hafWidth = halfWidth;
//			pNode->gameObjects = NULL;
//
//			vec2 offset;
//			float step = halfWidth * 0.5f;
//			for (int i = 0; i < 4; i++) {
//				offset.x = ((i & 1) ? step : -step);
//				offset.y = ((i & 2) ? step : -step);
//				/*	vec2 o(x, y);
//				offset = Point(o);*/
//				pNode->pChild[i] = BuildQuadtree(centre + offset, step, stopDepth - 1);
//			}
//			return pNode;
//		}
//	}
//
//void QuadT::InsertObject(Node* pTree, GameObjects* pObject)
//{
//	int index = 0; 
//	int straddle = 0; 
//	for (int i = 0; i < 2; i++) 
//	{
//		float delta = pObject->center[i] - pTree->center[i];
//		if (abs(delta) <= pObject->radius)
//		{
//			straddle = 1;
//			break;
//		}
//		if (delta > 0.0f) index |= (1 << i);
//	}
//	if (!straddle) 
//	{
//		if (pTree->pChild[index] == nullptr) 
//		{
//			pTree->pChild[index] = new Node;
//		}
//		InsertObject(pTree->pChild[index], pObject);
//	}
//	else
//	{
//		pObject->pNextObject = pTree->gameObjects;
//		pTree->gameObjects = pObject->pNextObject;
//	}
//}
//
//void QuadT::TestAllCollisions(Node* pTree) {
//	const int MAX_DEPTH = 40;
//	static Node* ancestorStack[MAX_DEPTH];
//	static int depth = 0;
//
//	ancestorStack[depth++] = pTree;
//	for (int n = 0; n < depth; n++) {
//		GameObjects* pA;
//		GameObjects* pB;
//		for (pA = ancestorStack[n]->gameObjects; pA; pA = pA->pNextObject)
//			for (pB = pTree->gameObjects; pB; pB = pB->pNextObject) {
//				if (pA == pB)
//					break;
//				TestCollision(pA, pB);
//			}
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (pTree->pChild[i])
//			TestAllCollisions(pTree->pChild[i]);
//	}
//	depth--;
//}
//
