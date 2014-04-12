#ifndef GAME_STATE_CONTROL_H
#define GAME_STATE_CONTROL_H

#include "cgamestateobject.h"
#include "CGraphics.h"
#include "CAudioManager.h"
#include "CTimer.h"
#include <sstream>
#include <string>
#include "keystatus.h"
#include "..\resource.h"
#include "CGameData.h"
#include "CLog.h"
#include "camera.h"

class cGameStateControl :  public cGameStateObject{
public:
  cGameStateControl(void);
  ~cGameStateControl(void);
  void initialize();
  void activate(CGameData &data);
  cGameStateObject* update(double timeDifference, Camera &cam, CGameData &data, CGraphics &con);
  void render(CGraphics &con, Camera &cam, CGameData &data);
  void processEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
  void deactivate();
  void resume();
  void pause();
  void save();
  void addTransitionEvent(int event, cGameStateObject* p_Next);

private:
  std::vector<TRANSITION_EVENT> m_TE; //stores all transition events
  CTimer m_timer;
  //bool m_bDone;
  int m_event;
  CMouse m_mouse;
  int m_viewChoice;
  //int m_currentSprite;

  //test
  //float m_badgeAngleX;
  //float m_badgeAngleZ;
  int m_transitionState;
  int m_levelScore;
};

#endif
