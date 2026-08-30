<template>
  <div id="keurs" class="keur" style="display: none;"></div>

  <div id=textTimer1></div>
  <div id="timer2"></div>
  <div id="textTimer2"></div>
  <div id="timer3"></div>
  <div id="bonne"></div>
  <div id="mauvaise"></div>

  <div class="top-buttons" style="display: none;">
    <button class="btn" id="btn2" onclick="restartv2()">Restart</button>
  </div>
  <ul id="game" class="flex-container"></ul>

  <div class="rectangle3" style="display: none;">
    <div class="texte">ez win</div>
  </div>

  <div class="rectangle4" style="display: none;">
    <div class="texte">noob</div>
  </div>
</template>

<script>
export default {
  name: 'GamePlayLegacy',
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
