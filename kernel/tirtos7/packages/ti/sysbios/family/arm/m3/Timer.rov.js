/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== Timer.rov.js ========
 */

var moduleName = "ti.sysbios.family.arm.m3::Timer (SysTick)";

var Program = xdc.module('xdc.rov.Program');

var viewMap = [
    {name: "Basic", fxn: "viewTimerBasic", structName: "BasicInfo"},
];

/*
 * Timer Object Basic Information
 */
function BasicInfo()
{
    this.address = null;
    this.symbol = null;
    this.device = null;
    this.startMode = null;
    this.runMode = null;
    this.period = null;
    this.periodType = null;
    this.intNum = null;
    this.tickFxn = null;
    this.arg = null;
    this.extFreq = null;
    this.hwiHandle = null;
}

/*
 * ======== toHexString ========
 * converts a number to a hex string with "0x" prefix.
 */
function toHexString(num) {
    return ("0x" + Number(num).toString(16));
}

/*
 * ======== toPaddedHexString ========
 * converts a number to a hex string with "0x" prefix.
 * inserts up to (len - 1) leading zeros.
 * up to a max of 7 zeros.
 */
function toPaddedHexString(number, len)
{
    return ("0x" + ("0000000" + number.toString(16)).substr(-len));
}

/*
 *  ======== viewGetTimerObjectArray ========
 *  returns an array of the current Timer objects.
 */
function viewGetTimerObjectArray()
{
    timerArray = new Array();

    try {
        var modState = Program.fetchVariable("ti_sysbios_family_arm_m3_Timer_Module_state");
    }
    catch (e) {
        return (timerArray);
    }
    var modStateAddr = Program.lookupSymbolValue("ti_sysbios_family_arm_m3_Timer_Module_state");
    var timerStructType = Program.lookupType("ti_sysbios_family_arm_m3_Timer_Struct");
    var offsetOfObjElem = timerStructType.member.objElem.offset;
    var next = modState.objQ.next;
    var timerAddr;

    while (Number(next) != Number(modStateAddr)) {
        timerAddr = next - offsetOfObjElem;
        var timer = new Object();
        timer = Program.fetchFromAddr(timerAddr, "ti_sysbios_family_arm_m3_Timer_Struct", 1);
        timer.$addr = timerAddr;
        timerArray.push(timer);
        next = timer.objElem.next;
    }

    return (timerArray);
}

/*
 *  ======== viewInitBasic ========
 */
function viewInitBasic(view, obj)
{
    view.address = toHexString(obj.$addr);
    view.device = "SysTick";

    if (obj.startMode == 0) {
        view.startMode = "StartMode_AUTO";
    }
    else {
        view.startMode = "StartMode_USER";
    }

    if (obj.runMode == 0) {
        view.runMode = "RunMode_CONTINUOUS";
    }
    else if (obj.runMode == 1) {
        view.runMode = "RunMode_ONESHOT";
    }
    else {
        view.runMode = "RunMode_DYNAMIC";
    }

    view.period = obj.period;
    if (obj.periodType == 0) {
        view.periodType = "PeriodType_MICROSECS";
    }
    else {
        view.periodType = "PeriodType_COUNTS";
    }
    view.intNum = obj.intNum;
    view.tickFxn = String(Program.lookupFuncName(Number(obj.tickFxn)));
    view.arg = obj.arg;

    view.extFreq = Number(obj.extFreq.lo).toString(10);
    view.hwiHandle = obj.hwi;
    view.symbol = String(Program.lookupDataSymbol(Number(obj.$addr)));
    /*
     *  In case the dynamically created object was the first thing in the
     *  BIOS_heap.
     */
    if (view.symbol == "BIOS_heap") {
        view.symbol = "";
    }
}

/*
 *  ======== viewTimerBasic ========
 */
function viewTimerBasic()
{
    view = new Array();

    var timers = viewGetTimerObjectArray();

    for (var i = 0; i < timers.length; i++) {
        var obj = timers[i];
        var basicView = new BasicInfo();
        viewInitBasic(basicView, obj);
        view.push(basicView);
    }

    return (view);
}
