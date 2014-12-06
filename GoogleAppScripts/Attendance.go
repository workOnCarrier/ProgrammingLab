/*
_1_
https://script.google.com/macros/s/AKfycbzWL2h1-y01TgVkOshsEhkxbZT4xYfkfLdNFMdfBC-o/dev
https://script.google.com/macros/s/AKfycbyY2p-EvNKfcjkIgA8DWpUcrnJ9lQS7ew-kn_lg3EOwgNp5pdpf/exec
https://script.google.com/macros/s/AKfycbyY2p-EvNKfcjkIgA8DWpUcrnJ9lQS7ew-kn_lg3EOwgNp5pdpf/exec

https://developers.google.com/apps-script/quickstart/forms
http://www.googleappsscript.org/user-interface/list-box
http://www.googleappsscript.org/user-interface/check-box
http://www.googleappsscript.org/advanced-examples/insert-data-in-sheet-using-ui-forms
http://www.googleappsscript.org/advanced-examples/load-list-box-from-sheet
https://developers.google.com/apps-script/guides/web#deploying
https://developers.google.com/apps-script/reference/ui/list-box#setItemSelected(Integer,Boolean)
*/

// var openedSS = SpreadsheetApp.openByUrl('https://docs.google.com/spreadsheets/d/1VXF03q_IcWEvGy4xg4CwBHJ01O9F_g67Bnmr4TVEEPo/edit#gid=0');
// var sheetList1 = openedSS.getSheetByName("sampleDataSheet");//Spreadsheet must match with sheet name

// get the xml representation
// get the csv representation

//var spreadsheedUrl = 'https://docs.google.com/spreadsheets/d/1VXF03q_IcWEvGy4xg4CwBHJ01O9F_g67Bnmr4TVEEPo/edit#gid=0';
// var spreadsheedUrl = 'https://docs.google.com/spreadsheets/d/17fZAHQxYSYSEtYwg3Ei6bGhVvY4JK_6189-jXApDfv4/edit#gid=0';
// var targetSheetUrl = 'https://docs.google.com/spreadsheets/d/17fZAHQxYSYSEtYwg3Ei6bGhVvY4JK_6189-jXApDfv4/edit#gid=1840687013'

var spreadsheedUrl = 'https://docs.google.com/spreadsheets/d/1H4duVkCTXZ_RY0SH3esvIP1IPyDGCnO83bhCgthcK-8/edit#gid=0';
var targetSheetUrl = 'https://docs.google.com/spreadsheets/d/1H4duVkCTXZ_RY0SH3esvIP1IPyDGCnO83bhCgthcK-8/edit#gid=1804064913';

var xmlDoc = '';

var firstNameCol = 2;
var lastNameCol = 3;
var emailCol = 4;

var firstNameSet = 0; var lastNameSet = 0; var emailSet = 0;

function getResetSelectionXml() {
  return '<sel><ent type="lns" val="0" /><ent type="fns" val="0" /><ent type="ems" val="0" /></sel>';
}

function doGet(){
  var app = UiApp.createApplication().setTitle('myApp');
  var panel = app.createVerticalPanel();
  var grid = app.createGrid(7, 2).setId('myGrid');
  
  populateXml();
  
  var emailLabel = app.createLabel('E-Mail');
  var emailListBox = app.createListBox().setName('email_List').setWidth('200px').setId('emailBox').setWidth('250px').setVisibleItemCount(5);
      
  var FirstnameLabel = app.createLabel('First Name');
  var FirstnameListBox = app.createListBox().setName('fname').setId('fnameBox').setWidth('250px').setVisibleItemCount(5);
  var LastnameLabel = app.createLabel('Last Name');
  var LastnameListBox = app.createListBox().setName('lname').setId('lnameBox').setWidth('250px').setVisibleItemCount(5);
  populateList ( emailListBox, FirstnameListBox, LastnameListBox, xmlDoc );
  
  var nextSession = app.createLabel('Wish to register for next session')
  var nextSessionCheck = app.createCheckBox("Yes").setName('Yes').setId('yesBox');
  
  var submitButton = app.createButton('Submit');
  var clearButton = app.createButton('clear');
  var infoLabel = app.createLabel('info:')
      .setVisible(false).setId('info');
  grid.setCellPadding(5).setCellSpacing(5);
  
  var hidden = app.createHidden ('appXml','0').setId('hidden');
  hidden.setValue ( xmlDoc );                Logger.log ('xml Doc length:' + xmlDoc.length );
  app.add(hidden);
  
  var selection = app.createHidden ('selected','0').setId('selection');
  var selectionXml = getResetSelectionXml();
  selection.setValue(selectionXml);
  app.add(selection);

  grid.setWidget(0,0,LastnameLabel)      .setWidget(0,1,LastnameListBox)
    .setWidget(1, 0, FirstnameLabel)     .setWidget(1, 1, FirstnameListBox)
    .setWidget(2, 0, emailLabel)         .setWidget(2, 1, emailListBox)
    .setWidget(3, 0, nextSession)        .setWidget(3, 1, nextSessionCheck)
    .setWidget(4, 0, clearButton)        .setWidget(4, 1, submitButton)
                                         .setWidget(5, 1, infoLabel)
    .setWidget(6, 0, hidden )            .setWidget(6, 1, selection) ;
  
  var handler = app.createServerHandler('UpdateInSS').addCallbackElement(panel);
  submitButton.addClickHandler(handler);
  
  var emailSelectHandler = app.createServerHandler('handleEmailSelection').addCallbackElement(panel);
  emailListBox.addChangeHandler(emailSelectHandler);
  
  var FirstnameSelectHandler = app.createServerHandler('handleFirstNameSelection').addCallbackElement(panel);
  FirstnameListBox.addChangeHandler(FirstnameSelectHandler);
  
  var LastnameSelectHandler = app.createServerHandler('handleLastNameSelection').addCallbackElement(panel);
  LastnameListBox.addChangeHandler(LastnameSelectHandler);
  
  var clearhandler = app.createServerHandler('clearAllControls').addCallbackElement(hidden);
  clearButton.addClickHandler(clearhandler);

  panel.add(grid);
  app.add(panel);
  return app;
  
}
function handleFirstNameSelection (e){
  var app = UiApp.getActiveApplication();
  var value = e.parameter.fname;
  Logger.log('value selected is ' + value );
  
  var selectObj = e.parameter.selected;               Logger.log('object is : ' + selectObj);
  var firstNameSet = getfn ( selectObj );
  var lastNameSet  = getln ( selectObj );
  var emailSet     = getem ( selectObj );
  if ( lastNameSet == 1 && emailSet == 1 ){ setfn(app, selectObj) ; return app; }
  
  /////// process xml to populate the other boxes
    var openedSS = SpreadsheetApp.openByUrl( spreadsheedUrl );
        if ( openedSS == 0 ){Logger.log('openByUrl did not work');}
    var sheetList1 = openedSS.getActiveSheet();
        if ( sheetList1 == null ){Logger.log('gettting sheet did not work');}
    var numItemList1 = sheetList1.getLastRow();//-1 is to exclude header row
    var list1ItemArray = sheetList1.getRange(1,1,numItemList1,4).getValues();
  
  if ( emailSet == 0 )    { app.getElementById('emailBox').clear(); }
  if ( lastNameSet == 0 ) { app.getElementById('lnameBox').clear(); }

    for(var i=0; i<list1ItemArray.length; i++) {
      Logger.log( list1ItemArray[i][lastNameCol-1].trim().toUpperCase() + ':'+  value + ' ' + lastNameSet);
       if ( list1ItemArray[i][firstNameCol-1].trim().toUpperCase() == value )
       {
         if ( lastNameSet == 0 && emailSet    == 0) { // nothing is set
           var lnameb = app.getElementById('lnameBox').addItem(list1ItemArray[i][lastNameCol-1].trim().toUpperCase()); lnameb.setSelectedIndex(0);
           var embox = app.getElementById('emailBox').addItem(list1ItemArray[i][emailCol-1].trim().toLowerCase()); embox.setSelectedIndex(0);
         } else if ( lastNameSet    == 1 && emailSet    == 1 ) { // both are set
           break;
         } else {
           if ( lastNameSet    == 1 ) { // last name is set, only email needs to be set
             var lastName = e.parameter.lname;
             if ( list1ItemArray[i][lastNameCol-1].trim().toUpperCase() == lastName ) {
               var emailbox = app.getElementById('emailBox').addItem(list1ItemArray[i][emailCol-1].trim().toLowerCase() );
               emailbox.setSelectedIndex(0);
             } else { continue; }
           } else if ( emailSet    == 1 ) { // email is set, only lastname needs to be set
             var emailValue = e.parameter.email_List;
             if ( list1ItemArray[i][emailCol-1].trim().toLowerCase() == emailValue ) {
               var lnamebox = app.getElementById('lnameBox').addItem(list1ItemArray[i][lastNameCol-1].trim().toUpperCase() );
               lnamebox.setSelectedIndex(0);
             } else { continue; }
           }
         }
       }
    }
  setfn(app, selectObj) ;
  /////// 
    Logger.log('handle firstname selection invoked for '+ value );
  return app;
}

function handleLastNameSelection (e){
  var app = UiApp.getActiveApplication();
  var value = e.parameter.lname;
  Logger.log('value selected is ' + value );
  
  var selectObj = e.parameter.selected;               Logger.log('object is : ' + selectObj);
  var firstNameSet = getfn ( selectObj );
  var lastNameSet  = getln ( selectObj );
  var emailSet     = getem ( selectObj );
  if ( firstNameSet == 1 && emailSet == 1 ){ setln(app,selectObj); return app; }
  /////// process xml to populate the other boxes
    var openedSS = SpreadsheetApp.openByUrl( spreadsheedUrl );
        if ( openedSS == 0 ){Logger.log('openByUrl did not work');}
    var sheetList1 = openedSS.getActiveSheet();
        if ( sheetList1 == null ){Logger.log('gettting sheet did not work');}
    var numItemList1 = sheetList1.getLastRow();//-1 is to exclude header row
    var list1ItemArray = sheetList1.getRange(1,1,numItemList1,4).getValues();
  
  if ( emailSet == 0 )    { app.getElementById('emailBox').clear(); }
  if ( firstNameSet == 0 ) { app.getElementById('fnameBox').clear(); }

    for(var i=0; i<list1ItemArray.length; i++) {
       if ( list1ItemArray[i][lastNameCol-1].trim().toUpperCase() == value ) {
         Logger.log( list1ItemArray[i][lastNameCol-1].trim().toUpperCase() + ':'+  value + ' ' + firstNameSet);
         if ( firstNameSet == 0 && emailSet    == 0) { Logger.log('nothing is set');// nothing is set
           app.getElementById('fnameBox').addItem(list1ItemArray[i][firstNameCol-1].trim().toUpperCase() ).setSelectedIndex(0);
           app.getElementById('emailBox').addItem(list1ItemArray[i][emailCol-1].trim().toLowerCase() ).setSelectedIndex(0);
         } else if ( firstNameSet    == 1 && emailSet    == 1 ) { // both are set
           break;
         } else {
           if ( firstNameSet    == 1 ) { // first name is set, only email needs to be set
             var firstName = e.parameter.fname;
             if ( list1ItemArray[i][firstNameCol-1].trim().toUpperCase() == firstName ) {
               app.getElementById('emailBox').addItem(list1ItemArray[i][emailCol-1].trim().toLowerCase() ).setSelectedIndex(0);
             } else { continue; }
           } else if ( emailSet    == 1 ) { // email is set, only firstname needs to be set
             var emailValue = e.parameter.email_List;
             if ( list1ItemArray[i][emailCol-1].trim().toLowerCase() == emailValue ) {
               app.getElementById('fnameBox').addItem(list1ItemArray[i][firstNameCol-1].trim().toUpperCase() ).setSelectedIndex(0);
             } else { continue; }
           }
         }
       }
    }
  setln(app,selectObj);
  /////// 
    Logger.log('handle lastname selection invoked for '+ value );
  return app;
}


function handleEmailSelection (e){
  var app = UiApp.getActiveApplication();
  var value = e.parameter.email_List;
  
  var selectObj = e.parameter.selected;               Logger.log('object is : ' + selectObj);
  var firstNameSet = getfn ( selectObj );
  var lastNameSet  = getln ( selectObj );
  var emailSet     = getem ( selectObj );
  if ( firstNameSet == 1 && lastNameSet == 1 ){ setem( app, selectObj); return app; }
  Logger.log( " selected value : " + value );
  /////// process email selection impact on other controls
    var openedSS = SpreadsheetApp.openByUrl( spreadsheedUrl );
        if ( openedSS == 0 ){Logger.log('openByUrl did not work');}
    var sheetList1 = openedSS.getActiveSheet();
        if ( sheetList1 == null ){Logger.log('gettting sheet did not work');}
    var numItemList1 = sheetList1.getLastRow();//-1 is to exclude header row
    var list1ItemArray = sheetList1.getRange(1,1,numItemList1,4).getValues();
  Logger.log( " number of rows : " + numItemList1 ); Logger.log ( "lastnameset:" + lastNameSet + " firstNameSet:" + firstNameSet );
  
  if ( lastNameSet == 0 ) { app.getElementById('lnameBox').clear(); }
  if ( firstNameSet == 0 ) { app.getElementById('fnameBox').clear(); }

  for(var i=0; i<list1ItemArray.length; i++) { 
    Logger.log( list1ItemArray[i][emailCol-1] + ': email match :' + value );
     if ( list1ItemArray[i][emailCol-1].trim().toLowerCase() == value ) { 
       if ( firstNameSet == 0 && lastNameSet    == 0) { // nothing is set
         app.getElementById('fnameBox').addItem(list1ItemArray[i][firstNameCol-1].trim().toUpperCase()).setSelectedIndex(0);
         app.getElementById('lnameBox').addItem(list1ItemArray[i][lastNameCol-1].trim().toUpperCase()).setSelectedIndex(0);
       } else if ( firstNameSet    == 1 && lastNameSet    == 1 ) { // both are set
         break;
       } else {
         if ( firstNameSet    == 1 ) { // first name is set, only latname needs to be set
           var firstName = e.parameter.fname;
           if ( list1ItemArray[i][firstNameCol-1].trim().toUpperCase() == firstName ) {
             app.getElementById('lnameBox').addItem(list1ItemArray[i][lastNameCol-1].trim().toUpperCase()).setSelectedIndex(0);
           } else { continue; }
         } else if ( lastNameSet    == 1 ) { // lastName is set, only firstname needs to be set
           var lastName = e.parameter.lname;
             if ( list1ItemArray[i][lastNameCol-1].trim().toUpperCase() == lastName ) {
               app.getElementById('fnameBox').addItem(list1ItemArray[i][firstNameCol-1].trim().toUpperCase()).setSelectedIndex(0);
             } else { continue; }
         }
       }
     }
   }
  setem(app,selectObj);
  return app;
}

function clearAllControls ( e ) {
  Logger.log ( 'clearAllControls::: start' );
  firstNameSet = 0;  lastNameSet  = 0;  emailSet     = 0;
  
  var app = UiApp.getActiveApplication();
  var xmlStr = e.parameter.appXml;
    
  resetControls ( app, xmlStr );
  
  Logger.log ( 'clearAllControls::: end' );
  return app;
}
function resetControls( app, xmlStr ){
  var x = new Date() ;
  Logger.log("resetControls:: resetting the controlls : " + x );
  
  app.getElementById('emailBox').clear();
  app.getElementById('fnameBox').clear();
  app.getElementById('lnameBox').clear();
  
  populateList ( app.getElementById('emailBox'), app.getElementById('fnameBox'), app.getElementById('lnameBox'), xmlStr );
  
  app.getElementById('emailBox').setSelectedIndex(0);
  app.getElementById('fnameBox').setSelectedIndex(0);
  app.getElementById('lnameBox').setSelectedIndex(0);
  app.getElementById('yesBox').setValue(false);
  app.getElementById('selection').setValue( getResetSelectionXml() );
  var y = new Date();
  Logger.log("resetControls:: resetting the controlls : " + (y - x) + ' :: ' + y );
}
function UpdateInSS (e) {
  var app = UiApp.getActiveApplication();
  var email = e.parameter.email_List;
  var fname = e.parameter.fname;
  var lname = e.parameter.lname;
  var yesval = e.parameter.Yes;
  
  app.getElementById('info').setVisible(true).setText('data added for guest:"' + fname + ' ' + lname + '"  ' ).setStyleAttribute('color','red');
  Logger.log("adding to spread sheet " + fname +" " + lname +" "+ email);
  clearAllControls(e);
   
  var sheetAppObj = SpreadsheetApp.openByUrl( spreadsheedUrl );
  var sheet = sheetAppObj.setActiveSheet(sheetAppObj.getSheets()[1]);
  var lastRow = sheet.getLastRow();
  var time = new Date();
  var targetRange = sheet.getRange(lastRow+1, 1, 1, 5).setValues([[email,fname,lname,yesval,time]]);
  return app;
}

function openSpreadSheet( sourceSheetUrl )
{
  var ss = SpreadsheetApp.openByUrl(sourceSheetUrl);
  if ( ss == null )   {
    Logger.log('Sheet:' + sourceSheetUrl + '. could not be opened' );
    return null;
  }
  return ss;
}
function populateList ( emailListBox, FirstnameListbox, LastnameListBox , fromxml)
{
  // xmlDoc
  Logger.log( 'populateList::: start populate controls' ); //  Logger.log( ' checking local |->' + fromxml + '<-|');
  var document = XmlService.parse(fromxml);
  var entries = document.getRootElement().getChildren();
  var previousFirstName = '' ;
  var previousLastName = '' ;
  var previousEmail = '' ;
  //Add the items in ListBox  Logger.log("No of entries:" + entries.length );
  for(var i=0; i<entries.length; i++){
    var entry = entries[i];
    var firstName = entry.getAttribute('fn').getValue().trim().toUpperCase();
    if ( firstName != previousFirstName ) { FirstnameListbox.addItem( firstName ); previousFirstName = firstName; }
    var lastName = entry.getAttribute('ln').getValue().trim().toUpperCase();
    if ( lastName != previousLastName ) {      LastnameListBox.addItem( lastName ); previousLastName = lastName;  }
    var email = entry.getAttribute('e').getValue().trim().toLowerCase();
    if ( email != previousEmail ) { emailListBox.addItem( email ); previousEmail = email; }
  }
  //Logger.log( ' checking global -->' + xmlDoc + '<--');
  Logger.log ( 'populateList::: END populating controls ');
}

function populateList_old( emailListBox, FirstnameListbox, LastnameListBox, xml )
{
  Logger.log('populateList::: start');
  var openedSS = openSpreadSheet( spreadsheedUrl );
  var sheetList1 = openedSS.getActiveSheet();
  if ( sheetList1 == null ){Logger.log('gettting sheet did not work');}

  var numItemList1 = sheetList1.getLastRow()-1;//-1 is to exclude header row
  //get the item array
  var list1ItemArray = sheetList1.getRange(1,1,numItemList1,4).getValues();
  
  //Add the items in ListBox
  for(var i=0; i<list1ItemArray.length; i++){
    FirstnameListbox.addItem(list1ItemArray[i][firstNameCol-1]);
    LastnameListBox.addItem(list1ItemArray[i][lastNameCol-1]);
    emailListBox.addItem(list1ItemArray[i][emailCol-1]);
  }
//  Logger.log( ' checking global -->' + xmlDoc + '<--');
  Logger.log('populateList::: end');
}
function populateXml ()
{
  var openedSS = openSpreadSheet( spreadsheedUrl );
  var sheetList1 = openedSS.getActiveSheet();
  if ( sheetList1 == null ){Logger.log('gettting sheet did not work');}

  var numItemList1 = sheetList1.getLastRow();//-1 is to exclude header row
  var list1ItemArray = sheetList1.getRange(1,1,numItemList1,4).getValues();
  
  // create an xml document
  var root = XmlService.createElement('nameList');
  
  //Add the items in ListBox
  for(var i=0; i<list1ItemArray.length; i++){
    var child = XmlService.createElement('ne'); // name element -- ne
       child.setAttribute('rN', i) // row number -- rn
            .setAttribute('fn', list1ItemArray[i][firstNameCol-1]) // name -- n
            .setAttribute('ln', list1ItemArray[i][lastNameCol-1]) // name -- n
            .setAttribute('e', list1ItemArray[i][emailCol-1]); // email -- e
    root.addContent(child);
  }
  var document = XmlService.createDocument(root);
  var docstr = XmlService.getRawFormat().format(document);
  // Logger.log(docstr);
  Logger.log ( 'setting global xml' );
  xmlDoc = docstr;
}

function getfn ( selectObj ){    // '<sel><ent type="lns" val="0" /><ent type="fns" val="0" /><ent type="ems" value="0" /></sel>'
  Logger.log('getfn: start' );
  var value = getSelectedParameter ( selectObj, 'fns' );
  Logger.log ('getfn: end' );
  return value;
}
  
function getSelectedParameter ( selectObj, identifier ){
  Logger.log ( 'getSelectedParameter : start with param - ' + identifier + ' and obj ' + selectObj );
  var document = XmlService.parse(selectObj);
  var entries = document.getRootElement().getChildren();
  var value = 0;
  for ( var i = 0 ; i < entries.length; i++ ) {
    var entry = entries[i];
    if ( entry.getAttribute ( 'type').getValue() == identifier ) {
      value = entry.getAttribute ( 'val' ).getValue();
      break;
    }
  }
  Logger.log('getSelectedParameter: end :: Value - '  + value );
  return value;
}

function getln ( selectObj ){
  Logger.log('getln: start' );
  var value = getSelectedParameter ( selectObj, 'lns' );
  Logger.log ('getln: end' );
  return value;
}
function getem ( selectObj ){
  Logger.log('getem: start' );
  var value = getSelectedParameter ( selectObj, 'ems' );
  Logger.log ('getem: end' );
  return value;
}

function setln ( app, selectObj ) {
  Logger.log('setln: start' );
  var document = setSelectParameter ( selectObj, 'lns' );
  app.getElementById('selection').setValue(document);
  Logger.log ( 'setln: end' );
}
function setfn ( app, selectObj ) {
  Logger.log('setfn: start' );
  var document = setSelectParameter ( selectObj, 'fns' );
  app.getElementById('selection').setValue(document);
  Logger.log ( 'setfn: end' );
}
function setem ( app, selectObj ) {
  Logger.log('setem: start' );
  var document = setSelectParameter ( selectObj, 'ems' );
  app.getElementById('selection').setValue(document);
  Logger.log ( 'setem: end' );
}

function setSelectParameter ( selectObj, identifier ) {
  Logger.log ( 'setSelectParameter : start with param - ' + identifier );
  var document = XmlService.parse(selectObj);
  var entries = document.getRootElement().getChildren();
  var lastNameSet = 0;
  for ( var i = 0 ; i < entries.length; i++ )
  {
     var entry = entries[i];
    if ( entry.getAttribute ( 'type').getValue() == identifier ) {
      entry.getAttribute ( 'val' ).setValue('1');
      break;
    }
  }
  Logger.log('setSelectParameter: end ' + XmlService.getPrettyFormat().format(document) );
  var docstr = XmlService.getRawFormat().format(document);
  return docstr;
}
