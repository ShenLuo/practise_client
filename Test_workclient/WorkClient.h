
#ifndef WORK_DEFINE_H_
#define WORK_DEFINE_H_

// 服务器发送给客户端
#define MSG_SERVER_TO_CLIENT_SUCCESS_SIGNIN    "success_sign_in"
#define MSG_SERVER_TO_CLIENT_SUCCESS_LOGININ   "success_login_in"
#define MSG_SERVER_TO_CLIENT_SUCCESS_LOGINOUT  "success_login_out"
#define MSG_SERVER_TO_CLIENT_WORKDATA		   "work_data"

// 客户端发送给服务器
#define MSG_CLIENT_TO_SERVER_SIGNIN			  "sign_in"
#define MSG_CLIENT_TO_SERVER_LOGININ		  "login_in"
#define MSG_CLIENT_TO_SERVER_LOGINOUT         "login_out"

enum 
{
	WIN_NULL,
	WIN_LOGIN,
	WIN_SIGNIN,
	WIN_DATA,
};

#endif // WORK_DEFINE_H_
