/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
var vpnAlreadyCall = false;
var configUrl ="https://webform.prod.adp.fr/";
var intervalId;


var app = {
    
    
    // Application Constructor
initialize: function() {
    this.bindEvents();
},
    // Bind Event Listeners
    //
    // Bind any events that are required on startup. Common events are:
    // 'load', 'deviceready', 'offline', and 'online'.
bindEvents: function() {
    document.addEventListener('deviceready', this.onDeviceReady, false);
},
    // deviceready Event Handler
    //
    // The scope of 'this' is the event. In order to call the 'receivedEvent'
    // function, we must explicity call 'app.receivedEvent(...);'
onDeviceReady: function() {
    
    app.receivedEvent('deviceready');
    ADP.POM.managers.coreManager.InitMenu();
    ADP.POM.managers.coreManager.GetIpadName(function (result){
                                             console.log('Ipad : ' + result);
                                             });
    
    //When authenticationChange checkAuthenticated
    window.setTimeout(function(){
                      ADP.POM.managers.coreManager.OnLevel2SecurityInfoChange(app.checkAuthenticated);
                      },10000);
    
    
    var appp = (typeof AppPreferences !== "undefined") ? new AppPreferences () : plugins.appPreferences;
    
    appp.fetch (
                function(result) {
                if(result[result.length - 1] != '/')
                result = result + '/';
                //if(resultresult.length-1) != '/')
                // result = result + '/';
                console.log('Url: ' + result);
                configUrl = result;
                //check authenticated , if authenticated navigation to configURL
                window.setTimeout(app.checkAuthenticated(),7000);
                app.testRelaunchAutomaticVpn();
                
                },
                function(error) {alert("Failed to retrieve a setting: " + error);},
                
                'Url'
                );
    
},
checkAuthenticated: function(){
    ADP.POM.managers.coreManager.Level2SecurityInfo(function(result){
                                                    var parentElement = document.getElementById('deviceready');
                                                    var receivedElement = parentElement.querySelector('.received');
                                                    console.log("success: ");
                                                    console.log(result);
                                                    if  (result==null)
                                                    receivedElement.innerHTML  = "Veuillez vous authentifier à l'aide du menu ci-dessus";
                                                    else{
                                                    if(navigator.onLine){
                                                    receivedElement.innerHTML  = "Vérification du VPN ...";
                                                    window.setTimeout(app.ping(configUrl),500);
                                                    } else{
                                                    window.setTimeout(function(){app.retry(configUrl)},1000);
                                                    }
                                                    }
                                                    },function(result){
                                                    
                                                    var parentElement = document.getElementById('deviceready');
                                                    var receivedElement = parentElement.querySelector('.received');
                                                    console.log(result);
                                                    if (result.toString().indexOf("authentication")>0){
                                                    
                                                    setTimeout(function(){receivedElement.innerHTML  = "<div class='banderol'> <div class='text'><font size='20'>Bienvenue sur First</font><p><font size='6'>Veuillez-vous connecter<br>depuis le menu POM en haut à droite</font></div></div>";},2000);
                                                    
                                                    }
                                                    else{
                                                    receivedElement.innerHTML  = "Une erreur s'est produite: "+ result;
                                                    }
                                                    }
                                                    );
},
    retry : function(configUrl){
        var parentElement = document.getElementById('deviceready');
        var receivedElement = parentElement.querySelector('.received');
        if(navigator.onLine)
        {
            receivedElement.innerHTML  = "Vérification du VPN ...";
            window.setTimeout(app.ping(configUrl),500);
        }
        else{
            receivedElement.innerHTML  = "Aucun réseau de disponible.";
            setTimeout(function(){app.retry(configUrl);},5000);
        }
        
    },
    ping : function(configUrl){
        console.log('try ping');
        
        $.ajax(
               {
               url : configUrl + "Resources/Ping/",
               type: 'GET',
               timeout: 5000,
               dataType: 'json',
               success: function(data){
               if(data && data.data){
               console.log('ping OK go to url');
               var parentElement = document.getElementById('deviceready');
               var receivedElement = parentElement.querySelector('.received');
               receivedElement.innerHTML  = "<div class='banderol'><div class='text'><font size='5'>Ouverture de l'url : " + configUrl + "</font></div></div>";
               ADP.POM.managers.coreManager.PostClaims(configUrl+"/Account/PostClaims",configUrl);
               //window.setTimeout(function(){window.location = configUrl;},1000);
               }
               else
               {
               console.log('ping bad response');
               
               window.setTimeout(function(){
                                 app.ping(configUrl);
                                 },5000);
               }
               },
               error: function(){
               console.log('ping no response');
               window.setTimeout(function(){
                                 app.ping(configUrl);
                                 },5000);
               }
               });
    },
    
    // Update DOM on a Received Event
receivedEvent: function(id) {
    var parentElement = document.getElementById(id);
    var listeningElement = parentElement.querySelector('.listening');
    var receivedElement = parentElement.querySelector('.received');
    
    listeningElement.setAttribute('style', 'display:none;');
    receivedElement.setAttribute('style', 'display:block;');
    
    console.log('Received Event: ' + id);
},
testRelaunchAutomaticVpn: function(){
    $.ajax(
           {
           url : configUrl + "Resources/Ping/",
           type: 'GET',
           timeout: 5000,
           dataType: 'json',
           success: function(data){
           setTimeout(function(){app.testRelaunchAutomaticVpn();},10000)
           console.log("success");
           console.log(data);
           },
           error: function(data){
           console.log("error");
           console.log(data);
           setTimeout(function(){app.testRelaunchAutomaticVpn();},5000);
           }
           });
}
    
};

setTimeout(function(){
           ADP.POM.managers.coreManager.OnLevel2PreSignOut(ADP.POM.managers.coreManager.RequestLevel2SignOut());
           },10000);
ADP.POM.managers.coreManager.OnMessageRaised(function(result){
                                             console.log(result);
                                             console.log(result.Message);
                                             console.log(result!=undefined);
                                             console.log((result.Message.indexOf("Authentification"))> -1);
                                             var parentElement = document.getElementById('deviceready');
                                             var receivedElement = parentElement.querySelector('.received');
                                             var type="";
                                             var message="";
                                             var toast ="showNoticeToast";
                                             
                                             if(result!=undefined){
                                             switch  (result.Type){
                                             case 0:
                                             type = "Erreur";
                                             toast="showErrorToast";
                                             break;
                                             
                                             case 1:
                                             type = "Attention";
                                             toast="showWarningToast";
                                             break;
                                             
                                             case 2:
                                             type= "Information";
                                             toast="showNoticeToast";
                                             break;
                                             }
                                             console.log("ici 1");
                                             
                                             message = type + ": " + result.Message;
                                             console.log("ici 1");
                                             console.log(message);
                                             
                                             $("#message").text(message);
                                             $(".event.message").show();
                                             
                                             setTimeout(function(){
                                                        $(".event.message").fadeOut("slow");
                                                        },8000);
                                             
                                             }
                                             });


